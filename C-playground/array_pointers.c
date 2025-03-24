/*
Proper use of pointer arithmetic
Array initialization techniques
Demonstration of pointer-to-array and pointer-to-multi-dimensional array
3D array implementation with pointer access
Memory address and pointer arithmetic demonstration
*/


#include <stdio.h>

#define ARRAY_SIZE 10
#define SUB_ARRAY_SIZE (ARRAY_SIZE - 3)
#define DEPTH 3


int global_sum = 0;

// Function to calculate sum of array elements using pointer arithmetic
int* calculate_sum(int *arr) {
    global_sum = 0; // Reset global_sum before calculation
    for (int i = 0; i < ARRAY_SIZE; i++) {
        global_sum += *(arr + i);
    }
    return &global_sum;
}

// Function to calculate difference of array elements using array notation
int calculate_difference(int arr[]) {
    int difference = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        difference -= arr[i];
    }
    return difference;
}

int main() {
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, [7] = 89}; // Partial array initialization
    
    printf("array[2] = %d, array[8] = %d, array[7] = %d, Array length = %d\n", 
           array[2], array[8], array[7], (int)(sizeof(array) / sizeof(array[0])));
    
    printf("Array elements using pointer notation : ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");

    printf("Memory location of array = %p\n", (void*)array);

    // Passing array to functions
    int *sum_result = calculate_sum(array);
    printf("Sum of array elements = %d\n", *sum_result);
    
    int diff_result = calculate_difference(array);
    printf("Difference of array elements = %d\n", diff_result);

    // Pointer to entire array
    int (*ptr_to_array)[ARRAY_SIZE] = &array;
    printf("array[7] using pointer to array = %d\n", *(*ptr_to_array + 7));




    // 2D array demonstration
    int matrix[ARRAY_SIZE][SUB_ARRAY_SIZE] = {{1, 9, 3, 4}, {1, 2, 6, 4}};
    printf("matrix[0][1] using pointer notation = %d\n", *(*matrix + 1));

    // Pointer to 1D array inside 2D array
    int (*ptr_to_row)[SUB_ARRAY_SIZE] = matrix;
    printf("matrix[0][1] = %d, matrix[1][2] = %d\n", (*ptr_to_row)[1], (*(ptr_to_row + 1))[2]);

    // Demonstrating pointer arithmetic on arrays
    int *ptr = array;
    printf("First element = %d, Second element = %d\n", *ptr, *(ptr + 1));
    ptr += 2;
    printf("Third element using pointer = %d\n", *ptr);
	
	
	
	// 3D array demonstration
    int cube[DEPTH][ARRAY_SIZE][SUB_ARRAY_SIZE] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}},
        {{9, 10, 11, 12}, {13, 14, 15, 16}},
        {{17, 18, 19, 20}, {21, 22, 23, 24}}
    };
    
    printf("cube[2][1][3] = %d\n", cube[2][1][3]);
    printf("cube[0][0][1] using pointer notation = %d\n", *(*(*(cube + 0) + 0) + 1));
    
    int (*ptr_to_cube)[ARRAY_SIZE][SUB_ARRAY_SIZE] = cube;
    printf("cube[0][0][2] = %d, cube[2][1][3] = %d\n", (*ptr_to_cube)[0][2], (*(ptr_to_cube + 2))[1][3]);

    return 0;
}
