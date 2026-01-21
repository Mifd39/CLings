// Learning Goal: Understand `break` and `continue` statements in loops.
/*
    Context:
    Sometimes you want to skip an iteration of a loop without stopping the whole thing.
    For that, you use `continue`.
    Other times, you found what you were looking for and want to stop the loop immediately.
    For that, you use `break`.
*/

#include <stdio.h>

// I AM NOT DONE

int main() {
    // TODO: Write a loop that prints numbers from 1 to 10.
    // However:
    // 1. If the number is 5, skip printing it (use continue).
    // 2. If the number is 8, stop the loop entirely (use break).

    for (int i = 1; i <= 10; i++) {
        // Your code here

        printf("%d\n", i);
    }

    return 0;
}
