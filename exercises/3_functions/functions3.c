// Learning Goal: Use function prototypes and definitions.
//
// In C, if you call a function before it is defined, you must declare its "prototype" first.
// A prototype tells the compiler about the function's name, return type, and parameters,
// without providing the actual body code.
//
// This allows you to define the function body later in the file (e.g., after main).

#include <stdio.h>

// I AM NOT DONE

// TODO: Declare the prototype for 'multiply' here.
// It should take two ints and return an int.


int main() {
    int product = multiply(4, 5);
    printf("The product is %d\n", product);
    return 0;
}

// TODO: Define the 'multiply' function here to return the product of two integers.
