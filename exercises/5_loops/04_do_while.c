// Learning Goal: Understand the Do-While Loop.
/*
    Context:
    Most loops check their condition *before* running. But what if you need the code to run at least once?
    For example, asking a user for a password: you have to ask first before you can check if it's correct.
    The 'do-while' loop guarantees that the code block runs once before the condition is checked.
*/
//
// A 'do-while' loop is similar to a 'while' loop, but it guarantees that the code block
// is executed AT LEAST ONCE before checking the condition.
//
// Syntax:
// do {
//    ...
// } while (condition);

#include <stdio.h>

// I AM NOT DONE

int main() {
    int count = 0;

    // TODO: Write a do-while loop that increments 'count' by 1
    // and continues while 'count' is less than 5.


    printf("Count is: %d\n", count);

    if (count == 5) {
        printf("Do-while loop works!\n");
    } else {
        printf("Expected count to be 5, got %d\n", count);
        return 1;
    }

    return 0;
}
