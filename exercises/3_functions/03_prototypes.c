// Learning Goal: Use function prototypes and definitions.
/*
    Context:
    In C, the compiler reads files from top to bottom. If you use a function before defining it,
    the compiler gets confused because it hasn't seen it yet.
    A "prototype" is a promise to the compiler: "I will define this function later, but here is what it looks like."
    This allows you to organize your code with 'main' at the top and helper functions below.
*/

#include <stdio.h>

// I AM NOT DONE

// TODO: Add the missing function prototype here.


int main() {
    int product = multiply(4, 5);
    printf("The product is %d\n", product);
    return 0;
}

// TODO: Define the 'multiply' function here to return the product of two integers.
