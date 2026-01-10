// Learning Goal: Understand how to print variables using printf format specifiers.
/*
    Context:
    When we want to see what's inside a variable, we can't just throw the variable name at `printf`.
    We need to use a placeholder, or "format specifier", to tell `printf` where to put the value and how to format it.
    It's like fill-in-the-blanks: "The value is ____".
    For integers, the placeholder is `%d` (for decimal number).
*/
//
// 'printf' uses format specifiers (placeholders) to print variables.
// Common specifiers:
// %d - Integer (decimal)
// %f - Float
// %c - Character
// %s - String
//
// If you use the wrong specifier, the output will be incorrect or the program might crash.

#include <stdio.h>

// I AM NOT DONE

int main() {
    int x = 10;
    // TODO: Fix the print statement so it correctly displays the value of the integer 'x'.
    printf("The value is %s\n", x);
    return 0;
}
