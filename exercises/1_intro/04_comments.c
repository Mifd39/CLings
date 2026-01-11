// Learning Goal: Understand how to use comments to document code or disable parts of it.
/*
    Context:
    Comments are like notes in the margins of a book. They help you (and others) understand
    what the code is doing without affecting how the program runs. The computer completely ignores them.
    You can also use comments to temporarily "turn off" code that you don't want to run, which is called "commenting out".
*/
//
// In C, single-line comments start with //
// Multi-line comments start with /* and end with */

#include <stdio.h>

// I AM NOT DONE

int main() {
    // TODO: Comment out the line below so the program can compile and run successfully.
    printf("This line causes an error because it's missing a semicolon")

    printf("This line should print.\n");
    return 0;
}
