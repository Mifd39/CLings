// Learning Goal: Use switch statements with Enums.
/*
    Context:
    When you have a variable that can be one of many specific values (like our Enum),
    a long chain of `if... else if... else if...` gets messy.
    The `switch` statement is a cleaner alternative designed exactly for this situation.
    It jumps directly to the matching "case", making your code more organized and often faster.
*/

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
    // TODO: Implement the switch statement to handle 'op' and perform the correct calculation.
    // Remember to return the result.


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
