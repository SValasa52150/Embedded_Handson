/*
`malloc()`   : Allocates memory for 5 integers without initializing them  / initializing to garbage value             
`calloc()`   : Allocates memory for 5 integers and initializes them to zero            
`realloc()`  : Resizes an existing allocated memory block from 5 to 8 integers         
`free()`     : Frees all allocated memory to prevent memory leaks                      
 */

#include <stdio.h>
#include <stdlib.h>  // Required for malloc, calloc, realloc, free

int main() {
    int *arr_malloc, *arr_calloc, *arr_realloc;
    int i;

    // ------------------------ malloc() Demo ------------------------
    printf("Using malloc() to allocate memory for 5 integers:\n");
    arr_malloc = (int *)malloc(5 * sizeof(int));  // Uninitialized memory
    if (arr_malloc == NULL) {
        printf("Memory allocation with malloc failed.\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        arr_malloc[i] = i + 1;
        printf("arr_malloc[%d] = %d\n", i, arr_malloc[i]);
    }

    // ------------------------ calloc() Demo ------------------------
    printf("\nUsing calloc() to allocate memory for 5 integers (initialized to 0):\n");
    arr_calloc = (int *)calloc(5, sizeof(int));  // Initialized memory
    if (arr_calloc == NULL) {
        printf("Memory allocation with calloc failed.\n");
        free(arr_malloc);
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("arr_calloc[%d] = %d\n", i, arr_calloc[i]);  // All should be 0
    }

    // ------------------------ realloc() Demo ------------------------
    printf("\nUsing realloc() to resize malloc array to 8 integers:\n");
    arr_realloc = (int *)realloc(arr_malloc, 8 * sizeof(int));
    if (arr_realloc == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr_malloc);  // Important to free the original if realloc fails
        free(arr_calloc);
        return 1;
    }
    arr_malloc = arr_realloc;  // Update pointer to new block

    for (i = 5; i < 8; i++) {
        arr_malloc[i] = (i + 1) * 10;
    }

    for (i = 0; i < 8; i++) {
        printf("arr_malloc[%d] = %d\n", i, arr_malloc[i]);
    }

    // ------------------------ free() Demo ------------------------
    printf("\nFreeing all dynamically allocated memory...\n");
    free(arr_malloc);
    free(arr_calloc);

    printf("Memory successfully freed.\n");

    return 0;
}
