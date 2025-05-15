/*
 * File: string_operations.c
 * Description: Demonstrates common string operations and I/O functions in C.
 *              Also illustrates the difference between string literals and character arrays.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];

    /* Manually initialized character array with null terminator */
    char manual_array[50] = { 'w', 'a', 's', 'd', '\0' };
    printf("Manual character array: %s\n", manual_array);

    /* Accessing an unused element (may print garbage) */
    printf("Unused element [15] as integer: %d\n", manual_array[15]);
    printf("Unused element [15] as character: %c\n", manual_array[15]);

    /* Accessing character array from index 2 as string */
    printf("Character array from index [2]: %s\n", &manual_array[2]);

    /* Display initial strings */
    printf("\nInitial Strings:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    /* String length */
    printf("\nString Lengths:\n");
    printf("Length of str1: %zu\n", strlen(str1));
    printf("Length of str2: %zu\n", strlen(str2));

    /* Copy strings */
    strcpy(str3, str1);
    printf("\nAfter strcpy(str3, str1): %s\n", str3);

    strncpy(str3, str2, 3);
    str3[3] = '\0'; // Ensure null-termination
    printf("After strncpy(str3, str2, 3): %s\n", str3);

    /* Concatenate strings */
    strcat(str1, str2);
    printf("\nAfter strcat(str1, str2): %s\n", str1);

    strncat(str2, " - Peace", 4); // Appends " - P"
    printf("After strncat(str2, \" - Peace\", 4): %s\n", str2);

    /* String comparison */
    int cmp_result = strcmp("ABC", "ABD");
    printf("\nString Comparison (\"ABC\" vs \"ABD\"): ");
    if (cmp_result < 0) {
        printf("ABC is less than ABD\n");
    } else if (cmp_result > 0) {
        printf("ABC is greater than ABD\n");
    } else {
        printf("ABC is equal to ABD\n");
    }

    /* String literal vs character array */
    const char *string_literal = "Immutable";
    char character_array[] = "Mutable";

    printf("\nString Literal: %s\n", string_literal);
    printf("Character Array: %s\n", character_array);

    printf("Accessing first char of literal: %c (ASCII: %d)\n",
           string_literal[0], string_literal[0]);

    printf("String literal from index 3: %s\n", &string_literal[3]);

    // string_literal[0] = 'i'; // Undefined behavior if uncommented!

    character_array[0] = 'm'; // Valid modification
    printf("Modified Character Array: %s\n", character_array);

    printf("\nNote:\n- String literals are read-only.\n- Character arrays are modifiable.\n");

    /* --- Demonstrating Basic I/O Functions --- */

    char user_input[50];
    int single_char;

    printf("\nEnter a short string (using gets - unsafe): ");
    gets(user_input); // Not recommended, use fgets in real code
    puts("You entered (using puts):");
    puts(user_input);

    printf("\nEnter a single character (using getchar): ");
    single_char = getchar(); // Reads next available character
    printf("You entered (using putchar): ");
    putchar(single_char);
    printf("\n");

    return 0;
}
