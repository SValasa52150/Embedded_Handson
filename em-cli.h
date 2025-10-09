#ifndef EM_CLI_H
#define EM_CLI_H

/* Standard includes. */
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

/* Base type definitions */
typedef int base_type;
#define FALSE ((base_type)0)
#define PASS  ((base_type)1)
#define CUSTOM_CLI_MAX_COMMANDS 10 // Maximum number of commands

#define ARRAY_BASED_COMMAND_REGISTER ((base_type)1) 
//#undef ARRAY_BASED_COMMAND_REGISTER 
#undef DEBUG

/* Command Definition Struct */
typedef struct command_line_input {
    const char *command; // char command[10];
    const char *help_string; // char helpstring[30];
    base_type (*command_interpreter)(char *write_buffer, size_t write_buffer_len, const char *command_string);
    int8_t expected_number_of_parameters;
    base_type is_special_command; // Indicate if it's a special command
} CLI_Command_Definition;

#ifndef ARRAY_BASED_COMMAND_REGISTER
/* List Of Commands */
typedef struct command_input_list {
    const CLI_Command_Definition *command_line_definition;
    struct command_input_list *next;
} CLI_Definition_List_Item;
#endif

/* Command Registration Array */
#ifdef ARRAY_BASED_COMMAND_REGISTER
CLI_Command_Definition commands_array[CUSTOM_CLI_MAX_COMMANDS];
#endif
int command_count = 0;
char write_buffer[512];

/* Function Prototypes */
base_type register_command(const CLI_Command_Definition * const command_to_register);
base_type process_command(const char * const command_input, char *write_buffer, size_t write_buffer_len);
base_type get_number_of_parameters( const char *command_string );
const char *cli_get_parameter(const char *command_string, base_type wanted_parameter, base_type *parameter_string_length);

/* Help, Set, Get Command Function Prototypes */
base_type help_command_interpreter(char *write_buffer, size_t write_buffer_len, const char *command_string);
base_type set_command_interpreter(char *write_buffer, size_t write_buffer_len, const char *command_string);
base_type get_command_interpreter(char *write_buffer, size_t write_buffer_len, const char *command_string);

#endif /* EM_CLI_H */
