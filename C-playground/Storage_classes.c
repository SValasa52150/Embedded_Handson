/*
Demonstrates the use of auto, register, static, and extern storage classes.
 */

#include <stdio.h>

// ----------- Extern Storage Class -----------
extern int global_counter;  // Declared here, defined later

// Function to show static storage class behavior
void staticDemo() {
    static int staticVar = 0;  // Retains value between calls
    staticVar++;
    printf("Inside staticDemo(), staticVar = %d\n", staticVar);
}

// Function to show auto and register storage classes
void autoAndRegisterDemo() {
    auto int a = 5;  // Explicit use of auto (optional)
    register int r = 10;  // Request to store in CPU register (can't take address)
    printf("Inside autoAndRegisterDemo():\n");
    printf("auto a = %d\n", a);
    printf("register r = %d\n", r);
}

// Definition of extern variable
int global_counter = 100;

int main(void) {
    printf("------ Storage Class Demonstration ------\n\n");

    // Call auto and register demo
    autoAndRegisterDemo();
    printf("\n");

    // Call static demo multiple times
    printf("Calling staticDemo() 3 times:\n");
    staticDemo();
    staticDemo();
    staticDemo();
    printf("\n");

    // Use extern variable
    printf("Extern variable global_counter = %d\n", global_counter);
    global_counter += 50;
    printf("After modification, global_counter = %d\n", global_counter);

    return 0;
}
