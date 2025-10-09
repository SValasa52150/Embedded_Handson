#include "em-cli.h"

/* Initialize Commands */
const CLI_Command_Definition help_command = {
    "help",
    "\r\nhelp:\r\nLists all the registered commands\r\nCommands:\r\n",
    help_command_interpreter,
    -1
};

const CLI_Command_Definition set_command = {
    "set",
    "\r\nset:\r\nSets the passed value in system\r\n",
    set_command_interpreter,
    2    
};

const CLI_Command_Definition get_command = {
    "get",
    "\r\nget:\r\nGets the value from system\r\n",
    get_command_interpreter,
    1 
};

#ifndef ARRAY_BASED_COMMAND_REGISTER
static CLI_Definition_List_Item registered_commands =
{
	&help_command,	/* The first command in the list is always the help command, defined in this file. */
	NULL			/* The next pointer is initialised to NULL, as there are no other registered commands yet. */
};
#endif


/* Register Command Function */
base_type register_command(const CLI_Command_Definition * const command_to_register) {
	                         
    base_type is_registered = FALSE;
    
    #ifndef ARRAY_BASED_COMMAND_REGISTER
    static CLI_Definition_List_Item *last_command_in_list = &registered_commands;
    CLI_Definition_List_Item *new_list_item;
    /* Create a new list item that will reference the command being registered. */
    new_list_item = ( CLI_Definition_List_Item * ) malloc( sizeof( CLI_Definition_List_Item ) );
    #endif

    if (command_count < CUSTOM_CLI_MAX_COMMANDS) {
        #ifndef ARRAY_BASED_COMMAND_REGISTER
        if( new_list_item != NULL )
        {
		    /* Reference the command being registered from the newly created
		    list item. */
		    new_list_item->command_line_definition = command_to_register;

		    /* The new list item will get added to the end of the list, so
		    pxNext has nowhere to point. */
		    new_list_item->next = NULL;

		    /* Add the newly created list item to the end of the already existing
		    list. */
		    last_command_in_list->next = new_list_item;

		    /* Set the end of list marker to the new list item. */
		    last_command_in_list = new_list_item;
		
	    }
	    #else 
        commands_array[command_count] = *command_to_register;
        #endif
        command_count++;
        is_done = PASS;
    }
    
    return is_done;
}

/* Command Processing Function */
base_type process_command(const char * const command_input, char *write_buffer, size_t write_buffer_len) {
    base_type is_processed = PASS;
    const char *registered_command_string = NULL;
    base_type command_string_length;
    
    #ifdef ARRAY_BASED_COMMAND_REGISTER
    static int command_index = 0;
    if(command_index == 0) 
    {
        for (command_index = 0; command_index < command_count; command_index++) 
        {
            registered_command_string = commands_array[command_index].command;
	        command_string_length = strlen( registered_command_string );
	        
	        /* To ensure the string lengths match exactly, so as not to pick up
	        a sub-string of a longer command, check the byte after the expected
	        end of the string is either the end of the string or a space before
	   	    a parameter. */
		    if( ( command_input[ command_string_length ] == ' ' ) || ( command_input[ command_string_length ] == 0x00 ) )
		    {
	            if (strncmp(command_input, commands_array[command_index].command, strlen(commands_array[command_index].command)) == 0) 
	            {
	                printf("VAMSI : Command received - %s\n",registered_command_string);
	               /* The command has been found.  Check it has the expected
			      number of parameters.  If expected_number_of_parameters is -1,
				  then there could be a variable number of parameters and no
				  check is made. */
			       if( commands_array[command_index].expected_number_of_parameters >= 0 )
				       {
				       if( get_number_of_parameters( command_input ) != commands_array[command_index].expected_number_of_parameters )
					   {
					       is_processed = FALSE;
					   } else {
					       printf("VAMSI : Number of parameters are - %d\n",commands_array[command_index].expected_number_of_parameters);
					   }
				   }
                   break;
                }
            }
        }
    }
    
    if( is_processed == FALSE )
	{
		/* The command was found, but the number of parameters with the command
		was incorrect. */
		strncpy( write_buffer, "Incorrect command parameter(s).  Enter \"help\" to view a list of available commands.\r\n\r\n", write_buffer_len );
		printf("%s\n",write_buffer);
	}
	else if( ( is_processed == PASS ) && ( command_index < command_count) )
	{
	    printf("command_index is %d\n",command_index);
	    /* Call the callback function that is registered to this command. */
		is_processed = commands_array[command_index].command_interpreter( write_buffer, write_buffer_len, command_input);

		/* If is_processed is FALSE, then no further strings will be returned
		after this one */
		if( is_processed == FALSE )
		{
			command_index = 0;
		}
	}
	else
	{
		strncpy( write_buffer, "Command not recognised.  Enter 'help' to view a list of available commands.\r\n\r\n", write_buffer_len );
		is_processed = FALSE;
		printf("%s\n",write_buffer);
	}
    
    #else /* Linked list based command registry logic from here */
    
    static const CLI_Definition_List_Item *curr_command = NULL;
    
	if( curr_command == NULL )
	{
		/* Search for the command string in the list of registered commands. */
		for( curr_command = &registered_commands; curr_command != NULL; curr_command = curr_command->pxNext )
		{
			registered_command_string = curr_command->command_line_definition->command;
			command_string_length = strlen( registered_command_string );
		
			/* To ensure the string lengths match exactly, so as not to pick up
			a sub-string of a longer command, check the byte after the expected
			end of the string is either the end of the string or a space before
			a parameter. */
			if( ( command_input[ command_string_length ] == ' ' ) || ( command_input[ command_string_length ] == 0x00 ) )
			{
			   	if( strncmp( command_input, registered_command_string, command_string_length ) == 0 )
				{
				    printf("VAMSI : Command received - %s\n",registered_command_string);
					/* The command has been found.  Check it has the expected
					number of parameters.  If expected_number_of_parameters is -1,
					then there could be a variable number of parameters and no
					check is made. */
					if( curr_command->command_line_definition->expected_number_of_parameters >= 0 )
					{
					    if( prvGetNumberOfParameters( command_input ) != curr_command->command_line_definition->expected_number_of_parameters )
						{
						    is_processed = FALSE;
						} else {
						    printf("VAMSI : Number of parameters are - %d\n",curr_command->command_line_definition->expected_number_of_parameters);
						}
					}
					break;
				}
			}
		}
	}

	if( ( curr_command != NULL ) && ( is_processed == FALSE ) )
	{
		/* The command was found, but the number of parameters with the command
		was incorrect. */
		strncpy( write_buffer, "Incorrect command parameter(s).  Enter \"help\" to view a list of available commands.\r\n\r\n", write_buffer_len );
		curr_command = NULL;
		printf("%s\n",write_buffer);
	}
	else if( curr_command != NULL )
	{
	   	/* Call the callback function that is registered to this command. */
		is_processed = curr_command->command_line_definition->command_interpreter( write_buffer, write_buffer_len, command_input );

		/* If is_processed is FALSE, then no further strings will be returned
		after this one, and	curr_command can be reset to NULL ready to search
		for the next entered command. */
		if( is_processed == FALSE )
		{
			curr_command = NULL;
		}
	}
	else
	{
	    /* curr_command was NULL, the command was not found. */
		strncpy( write_buffer, "Command not recognised.  Enter 'help' to view a list of available commands.\r\n\r\n", write_buffer_len );
		is_processed = FALSE;
		printf("%s\n",write_buffer);
	}
    
    #endif

    return is_processed;
}

/* Help Command Implementation */
base_type help_command_interpreter(char *write_buffer, size_t write_buffer_len, const char *command_string) {
    const char *registered_command_string = NULL;
    base_type command_string_length;
    memset(write_buffer, 0, write_buffer_len);
    
    #ifdef ARRAY_BASED_COMMAND_REGISTER
    base_type command_index = 0;
    for (command_index = 0; command_index < command_count; command_index++) 
    {
        if(command_index == 0) continue;
        registered_command_string = commands_array[command_index].command;
        command_string_length = strlen( registered_command_string );
        
        if(command_index == 1) {
           strncpy(write_buffer, registered_command_string, command_string_length);
        } else {
            strcat(write_buffer,"\r\n"); 
            strcat(write_buffer,registered_command_string); 
        }
    }
    printf("VAMSI : List of commandss - %s%s","\n",write_buffer);
    #else
    const CLI_Definition_List_Item *command = &registered_commands;
    command = command->next->next;
    for( command ; command != NULL; command = command->next )
    {
        registered_command_string = command->command_line_definition->command;
        command_string_length = strlen( registered_command_string );
        
        if(strlen(write_buffer) == 0) {
        strncpy(write_buffer, registered_command_string, command_string_length);
        } else {
            strcat(write_buffer,"\r\n"); 
            strcat(write_buffer, registered_command_string); 
        }
    }
     printf("VAMSI : List of commands - %s%s","\n",write_buffer);
    #endif 

	 // Return FALSE if no more strings are to be returned
	 return (FALSE);
}

/* Set Command Implementation */
base_type set_command_interpreter(char *write_buffer, size_t write_buffer_len, const char *command_string) {
    char * parameter;
    base_type string_length = 0;
    
    /* Start with an empty string. */
    memset(write_buffer, 0, write_buffer_len);
    parameter = ( char * ) cli_get_parameter(command_string, 1, &string_length);
    strncpy(write_buffer, parameter, string_length);
    printf("VAMSI : Param 1- %s\n",write_buffer);
    
    /* Start with an empty string. */
    memset(write_buffer, 0, write_buffer_len);
    parameter = ( char * ) cli_get_parameter(command_string, 2, &string_length);
    strncpy(write_buffer, parameter, string_length);
    printf("VAMSI : Param 2- %s\n",write_buffer);

	// Return FALSE if no more strings are to be returned
	return (FALSE);
}

/* Get Command Implementation */
base_type get_command_interpreter(char *write_buffer, size_t write_buffer_len, const char *command_string) {
   
}


base_type get_number_of_parameters( const char *command_string )
{
base_type parameter_count = 0;
base_type is_last_character_space = FALSE;

	/* Count the number of space delimited words in command_string. */
	while( *command_string != 0x00 )
	{
		if( ( *command_string ) == ' ' )
		{
			if( is_last_character_space != PASS )
			{
				parameter_count++;
				is_last_character_space = PASS;
			}
		}
		else
		{
			is_last_character_space = FALSE;
		}

		command_string++;
	}

	/* If the command string ended with spaces, then there will have been too
	many parameters counted. */
	if( is_last_character_space == PASS )
	{
		parameter_count--;
	}

	/* The value returned is one less than the number of space delimited words,
	as the first word should be the command itself. */
	return parameter_count;
}


const char *cli_get_parameter(const char *command_string, base_type wanted_parameter, base_type *parameter_string_length)
{
base_type parameters_found = 0;
const char *return_param = NULL;


	*parameter_string_length = 0;
	
	while( parameters_found < wanted_parameter )
	{
		/* Index the character pointer past the current word.  If this is the start
		of the command string then the first word is the command itself. */
		while( ( ( *command_string ) != 0x00 ) && ( ( *command_string ) != ' ' ) )
		{
		    command_string++;
		}

		/* Find the start of the next string. */
		while( ( ( *command_string ) != 0x00 ) && ( ( *command_string ) == ' ' ) )
		{
		    command_string++;
		}
	
		/* Was a string found? */
		if( *command_string != 0x00 )
		{
			/* Is this the start of the required parameter? */
			parameters_found++;

			if( parameters_found == wanted_parameter )
			{
				/* How long is the parameter? */
				return_param = command_string;
				
				while( ( ( *command_string ) != 0x00 ) && ( ( *command_string ) != ' ' ) )
				{
					( *parameter_string_length )++;
					command_string++; 
				}
			
				if( *parameter_string_length == 0 )
				{
					return_param = NULL;
				}

				break;
			}
		}
		else
		{
			break;
		}
	}

	return return_param;
}



int main(void) {
	/* Register Help Command */
	register_command(&help_command);
	register_command(&set_command);
	register_command(&get_command);


	/* Process Example Command */
	process_command("set temp 25", write_buffer, sizeof(write_buffer));
	process_command("help", write_buffer, sizeof(write_buffer));
	process_command("copy file1 file2", write_buffer, sizeof(write_buffer));

	return 0;
}