#include <stdio.h>

int main(void) {
    int number = 7;

    // ----------------- if, else if, else -----------------
    printf("Conditional Statements:\n");
    if (number > 10) {
        printf("Number is greater than 10\n");
    } else if (number == 10) {
        printf("Number is equal to 10\n");
    } else {
        printf("Number is less than 10\n");
    }

    printf("\n");

    // ----------------- for loop -----------------
    printf("For Loop (0 to 4):\n");
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    printf("\n");

    // ----------------- while loop -----------------
    printf("While Loop (0 to 4):\n");
    int j = 0;
    while (j < 5) {
        printf("j = %d\n", j);
        j++;
    }

    printf("\n");

    // ----------------- do-while loop -----------------
    printf("Do-While Loop (0 to 4):\n");
    int k = 0;
    do {
        printf("k = %d\n", k);
        k++;
    } while (k < 5);

    printf("\n");

    // ----------------- switch statement -----------------
    printf("Switch Statement:\n");
    int option = 2;
    switch (option) {
        case 1:
            printf("Option is 1\n");
            break;
        case 2:
            printf("Option is 2\n");
            break;
        case 3:
            printf("Option is 3\n");
            break;
        default:
            printf("Invalid option\n");
    }

    printf("\n");

    // ----------------- break & continue -----------------
    printf("Break and Continue Example:\n");
    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            continue;  // skip printing 3
        }
        if (i == 7) {
            break;     // exit loop when i is 7
        }
        printf("i = %d\n", i);
    }

    printf("\n");

    // ----------------- goto statement -----------------
    printf("Goto Statement Example:\n");
    int x = 0;
    if (x == 0) {
        goto skip_to_here;
    }

    printf("This will be skipped\n");

skip_to_here:
    printf("Jumped using goto to this label!\n");

    return 0;
}
