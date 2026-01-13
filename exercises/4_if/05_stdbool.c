// Learning Goal: Understand boolean types and values in C.
/*
    Context:
    For a long time, C didn't have a built-in boolean type. Programmers used integers (0 for false, 1 for true).
    C99 introduced a standard library header which gives us 'bool', 'true', and 'false'.
    This makes code much more readable!
*/

#include <stdio.h>
// I AM NOT DONE

// TODO: Fix the compilation error by including the necessary header file for 'bool'.

int main() {
    bool is_sunny = true;
    bool is_raining = false;

    if (is_sunny && !is_raining) {
        printf("It's a beautiful day!\n");
    } else {
        printf("Stay inside.\n");
    }

    return 0;
}
