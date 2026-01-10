// Learning Goal: Understand how to use comments.
/*
    Context:
    Comments are notes for humans that the computer ignores completely.
    They are crucial for explaining *why* you did something.
    We can also use them to "disable" code without deleting it, which is great for debugging.
    In C, we have single-line comments // and multi-line comments / * ... * /.
*/

#include <stdio.h>

// I AM NOT DONE

int main() {
    printf("This line should run.\n");

    // TODO: Comment out the line below so the program stops crashing!
    printf("This line causes an error because it's incomplete...) // Missing quote and semicolon!

    printf("Great! The program runs now.\n");
    return 0;
}
