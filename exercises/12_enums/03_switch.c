// Learning Goal: Use switch statements with Enums.
//
// The 'switch' statement is a control flow structure that allows you to handle multiple cases efficiently.
// It is often used with enums to handle different states.
//
// Don't forget 'break' at the end of each case to prevent "fallthrough"!

#include <stdio.h>

// I AM NOT DONE

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
} Operation;

int calculate(int a, int b, Operation op) {
    int result = 0;
    // TODO: Use a switch statement to handle the different 'op' cases.
    // For DIVIDE, return 0 if b is 0.


    return result;
}

int main() {
    if (calculate(10, 5, ADD) == 15 && calculate(10, 5, DIVIDE) == 2) {
        printf("Switch statement works!\n");
    } else {
        printf("Something is wrong.\n");
        return 1;
    }
    return 0;
}
