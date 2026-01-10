// Learning Goal: Understand the basics of pointers and the address-of operator.
//
// A pointer is a variable that stores the memory address of another variable.
//
// To get the address of a variable, use the '&' (address-of) operator.
// To declare a pointer to an integer, use 'int *'.
//
// Example:
// int a = 10;
// int *ptr = &a; // ptr now holds the address of a

#include <stdio.h>

// I AM NOT DONE

int main() {
    int x = 42;
    // TODO: Create a pointer named 'p' that points to the variable 'x'.


    // The '*' operator (dereference) is used to access the value at the address stored in the pointer.
    printf("The value of x via pointer is %d\n", *p);
    return 0;
}
