// Learning Goal: Understand how to use bitwise operators to manage boolean flags.
/*
    Context:
    In systems programming, we often want to store multiple on/off settings (flags) efficiently.
    Instead of using an entire integer for each true/false value, we can use individual bits within a single integer.
    This is like having a row of light switches where each switch controls a different feature.
*/
//
// We use powers of 2 (1, 2, 4, 8...) to represent each unique bit position.
// | (OR) sets a flag (turns it on).
// & (AND) checks a flag (sees if it's on).
// ~ (NOT) combined with & clears a flag (turns it off).

#include <stdio.h>

#define FLAG_A 1  // 0001
#define FLAG_B 2  // 0010
#define FLAG_C 4  // 0100

// I AM NOT DONE

int main() {
    unsigned int flags = 0;

    // TODO: Set FLAG_A and FLAG_C.


    if ((flags & FLAG_A) && (flags & FLAG_C) && !(flags & FLAG_B)) {
        printf("Flags configured correctly!\n");
    } else {
        printf("Flags are incorrect: %d\n", flags);
    }

    return 0;
}
