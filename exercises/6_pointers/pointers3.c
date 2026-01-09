// Learning Goal: Pass pointers to functions (Pass by Reference).
//
// By default, C passes arguments by value (copying them).
// To modify a variable from inside a function, you need to pass its address (a pointer).
//
// This is often called "passing by reference".

#include <stdio.h>

// I AM NOT DONE

// TODO: Define a function named 'swap' that takes two int pointers (int *a, int *b).
// It should swap the values of the integers they point to.
// Hint: You'll need a temporary variable to hold one of the values during the swap.


int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    // TODO: Call the 'swap' function with the addresses of a and b.
    // Remember to use the '&' operator to get the addresses.


    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
