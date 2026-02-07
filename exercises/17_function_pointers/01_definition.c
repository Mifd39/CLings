// Learning Goal: Understand how to declare and use a function pointer.
/*
    Context:
    Function pointers allow you to store the address of a function in a variable.
    This is like storing a shortcut to a set of instructions.

    The syntax can be tricky: `return_type (*pointer_name)(argument_types)`.

    For example: `void (*greet)(void)` is a pointer to a function that returns void and takes no arguments.
*/
#include <stdio.h>

// I AM NOT DONE

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 10;
    int y = 20;

    // TODO: Declare a function pointer named 'operation' that takes two ints and returns an int.
    // Initialize it to point to the 'add' function.
    // Hint: int (*operation)(int, int) = ...;

    // TODO: Use the function pointer 'operation' to call the function with x and y.
    // Store the result in the 'result' variable.
    int result = 0;

    printf("Result: %d\n", result);

    return 0;
}
