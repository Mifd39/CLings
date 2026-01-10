// Learning Goal: Pass pointers to functions (Pass by Reference).
//
// By default, C passes arguments by value (copying them).
// To modify a variable from inside a function, you need to pass its address (a pointer).
//
// This is often called "passing by reference".

#include <stdio.h>

// I AM NOT DONE

// TODO: Define a function named 'swap' that swaps the values of two integers.
// The function should accept pointers to the integers.


int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    // TODO: Call the 'swap' function to swap the values of 'a' and 'b'.


    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
