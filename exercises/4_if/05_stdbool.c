// Learning Goal: Understand boolean types and values in C.
/*
    Context:
    For a long time, C didn't have a built-in boolean type. Programmers used integers (0 for false, 1 for true).
    C99 introduced <stdbool.h>, which gives us 'bool', 'true', and 'false'.
    This makes code much more readable!
*/
//
// <stdbool.h> defines the 'bool' type and the values 'true' and 'false'.
//

#include <stdio.h>
// I AM NOT DONE

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
