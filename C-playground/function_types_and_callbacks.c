#include <stdio.h>
/*
A callback function is:
A function passed as an argument to another function.
Later, this passed-in function is called back (i.e., executed) inside the receiving function.
This is useful when you want your function to behave differently depending on what function is passed in—flexibility and reusability!

int (*op)(int, int)
This declares a function pointer named func that points to a function taking two int arguments and returning an int.
In main(), we pass the add/sub/mul function as an argument to operate.
*/



#include <stdio.h>

// -------------------- Call by Value --------------------
void modifyByValue(int x) {
    x = x + 10;
    printf("Inside modifyByValue: x = %d\n", x);
}

// -------------------- Call by Reference --------------------
void modifyByReference(int *x) {
    *x = *x + 10;
    printf("Inside modifyByReference: *x = %d\n", *x);
}

// -------------------- Direct Recursion --------------------
void directRecursion(int n) {
    if (n == 0)
        return;
    printf("Direct recursion: %d\n", n);
    directRecursion(n - 1);
}

// -------------------- Indirect Recursion --------------------
void indirectRecursionB(int);  // Forward declaration

void indirectRecursionA(int n) {
    if (n <= 0)
        return;
    printf("Indirect recursion A: %d\n", n);
    indirectRecursionB(n - 1);
}

void indirectRecursionB(int n) {
    if (n <= 0)
        return;
    printf("Indirect recursion B: %d\n", n);
    indirectRecursionA(n - 1);
}

// -------------------- Tail Recursion --------------------
void tailRecursion(int n) {
    if (n == 0)
        return;
    printf("Tail recursion: %d\n", n);
    tailRecursion(n - 1);  // Recursive call is the last statement
}

// -------------------- Non-Tail Recursion --------------------
void nonTailRecursion(int n) {
    if (n == 0)
        return;
    nonTailRecursion(n - 1);  // Recursive call followed by more work
    printf("Non-tail recursion: %d\n", n);
}

// -------------------- Callback Functions --------------------
int add(int a, int b)     { return a + b; }
int subtract(int a, int b){ return a - b; }
int multiply(int a, int b){ return a * b; }

int operate(int x, int y, int (*op)(int, int)) {
    return op(x, y);  // Call the passed-in function
}

// -------------------- Main --------------------
int main(void) {
    // Call by value
    int a = 10;
    printf("Before modifyByValue: a = %d\n", a);
    modifyByValue(a);
    printf("After modifyByValue: a = %d\n\n", a);

    // Call by reference
    int b = 10;
    printf("Before modifyByReference: b = %d\n", b);
    modifyByReference(&b);
    printf("After modifyByReference: b = %d\n\n", b);

    // Direct recursion
    printf("----- Direct Recursion -----\n");
    directRecursion(3);
    printf("\n");

    // Indirect recursion
    printf("----- Indirect Recursion -----\n");
    indirectRecursionA(3);
    printf("\n");

    // Tail recursion
    printf("----- Tail Recursion -----\n");
    tailRecursion(3);
    printf("\n");

    // Non-tail recursion
    printf("----- Non-Tail Recursion -----\n");
    nonTailRecursion(3);
    printf("\n");

    // Callback functions
    printf("----- Callback Function Demo -----\n");
    printf("Add: %d\n", operate(10, 5, add));
    printf("Subtract: %d\n", operate(10, 5, subtract));
    printf("Multiply: %d\n", operate(10, 5, multiply));

    return 0;
}
