// Learning Goal: Understand how to pass functions as arguments (callbacks).
/*
    Context:
    A "callback" is a function passed as an argument to another function.
    The receiving function can then "call back" the passed function.

    This is useful for making generic functions. For example, a function that
    processes an array might take a callback to apply to each element.
*/
#include <stdio.h>

// I AM NOT DONE

void print_number(int n) {
    printf("Number: %d\n", n);
}

void print_square(int n) {
    printf("Square: %d\n", n * n);
}

// TODO: Define a function named 'process_array'.
// Arguments:
// 1. int *arr (the array)
// 2. int size (size of array)
// 3. void (*action)(int) (the function pointer)
//
// Logic:
// Loop through the array and call 'action' on each element: action(arr[i]);

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Printing numbers:\n");
    // TODO: Call process_array with the numbers array and print_number function.

    printf("\nPrinting squares:\n");
    // TODO: Call process_array with the numbers array and print_square function.

    return 0;
}
