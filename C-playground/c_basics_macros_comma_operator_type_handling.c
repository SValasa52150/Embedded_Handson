#include <stdio.h>

// Macro definitions
#define PI 3.141414

// Macro functions
#define GREATER(x, y) \
    if ((x) > (y)) { printf("X is greater\n"); } \
    else if ((x) < (y)) { printf("Y is greater\n"); } \
    else { printf("Both are equal\n"); }

#define SUM1(x, y) ((x) + (y))
#define SUM2(x, y) x+y

int main(void) {
	int int_input;
    float float_input;
	int i = 3;
    int j = -5;
    // ----------- Type Behavior Demo ----------
    printf("Integer division (5 / 2): %d\n", 5 / 2);
    printf("Floating-point as int (5.0 / 2): %d\n", (5.0 / 2));  // generates garbage value
    printf("Floating-point as int (5 / 2.0): %d\n", (int)(5 / 2.0)); // Corrected with cast
    printf("Floating-point as int (5.0 / 2.0): %d\n", (int)(5.0 / 2.0));

    printf("Float division results:\n");
    printf("%f\n", (float)(5 / 2));        // generates garbage value. It tries to read a floating-point value from the stack where an integer was actually pushed. Result: garbage value
    printf("%f\n", 5.0 / 2);
    printf("%f\n", 5 / 2.0);
    printf("%f\n", 5.0 / 2.0);

    // ----------- String Formatting ----------
    printf("%25s\n", "Helloooooooooo");
    printf("%.5s\n", "Helloooooooooo");

    // ----------- Integer & Unsigned Behavior ----------
    printf("Signed addition: %d\n", i + j);
    printf("Unsigned addition (may show large value if negative probably 2's complement): %u\n", i + j);

    // ----------- Constants ----------
    const int p = 33;
    printf("PI macro as float: %f\n", PI);
    printf("Const variable: %d\n", p);

    // ----------- Macro Function Demo ----------
    GREATER(243, 44);
    GREATER(243, 444);

    // ----------- Date & Time ----------
    printf("Compile Date: %s\n", __DATE__);
    printf("Compile Time: %s\n", __TIME__);

    // ----------- User Input ----------
    

    printf("Enter an integer: ");
    scanf("%d", &int_input);
    printf("You entered: %d\n", int_input);

    printf("Enter a float: ");
    scanf("%f", &float_input);
    printf("You entered: %f\n", float_input);

    // ----------- Macro Substitution Behavior ----------
	printf("Macro SUM1 used in expression (5 * SUM(3,4)): %d\n", 5 * SUM1(3, 4));
    printf("Macro SUM2 used in expression (5 * SUM(3,4)): %d\n", 5 * SUM2(3, 4));// Here just substitution of values takes place

    // ----------- Comma Operator ----------
    int value1 = (1, 2, 3, 4);  // Only last value is assigned
    printf("Value1 using comma operator: %d\n", value1);

    int value2;
    value2 = 5, 6;  // Equivalent to (value2 = 5), 6 is ignored
    printf("Value2 (5,6 assignment): %d\n", value2);
    printf("Value2 as ASCII char: %c\n", value2);

    // ----------- Character and ASCII ----------
    char character = 'd';
    printf("ASCII of 'd': %d\n", character);
    printf("Character: %c\n", character);

    return 0;
}
