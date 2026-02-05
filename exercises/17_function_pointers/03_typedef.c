// Learning Goal: Use typedef to simplify function pointer declarations.
/*
    Context:
    Function pointer syntax can be verbose and hard to read:
    `void (*callback)(int, float)`.

    Using typedef, we can give it a cleaner name:
    `typedef void (*CallbackType)(int, float);`

    Then we can just use `CallbackType my_func;`.
*/
#include <stdio.h>

// I AM NOT DONE

// TODO: Create a typedef named 'MathOp' for a function pointer that:
// - Takes two integers (int a, int b)
// - Returns an integer
// Hint: typedef int (*MathOp)(int, int);


int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// This function takes a MathOp typedef as an argument!
// (This will cause a compiler error until you define MathOp above)
void execute_op(int x, int y, MathOp op) {
    printf("Result: %d\n", op(x, y));
}

int main() {
    // TODO: Declare a variable 'my_op' of type MathOp and assign it to 'add'.
    MathOp my_op = NULL; // Change NULL to add

    execute_op(10, 5, my_op);

    // TODO: Reassign 'my_op' to 'subtract' and call execute_op again.

    return 0;
}
