// Learning Goal: Use arrays of function pointers for efficient dispatching.
/*
    Context:
    You can store function pointers in an array, just like any other type.
    This is often used to replace long switch-case statements.

    Instead of:
    switch(op) {
        case 0: func0(); break;
        case 1: func1(); break;
        ...
    }

    You can do: `functions[op]();`
*/
#include <stdio.h>

// I AM NOT DONE

void op_add(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}

void op_sub(int a, int b) {
    printf("%d - %d = %d\n", a, b, a - b);
}

void op_mul(int a, int b) {
    printf("%d * %d = %d\n", a, b, a * b);
}

int main() {
    // TODO: Create an array of function pointers named 'operations'.
    // It should hold pointers to functions that take two ints and return void.
    // Initialize it with: {op_add, op_sub, op_mul}.
    // Hint: void (*operations[])(int, int) = ...;

    int a = 10, b = 5;
    int choice = 0;

    // TODO: Use the array to call the function at index 'choice' with 'a' and 'b'.

    choice = 1;
    // TODO: Call the function at index 'choice'.

    choice = 2;
    // TODO: Call the function at index 'choice'.

    return 0;
}
