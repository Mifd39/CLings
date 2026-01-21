// Learning Goal: Understand how `sizeof` works (and fails) with arrays passed to functions.
/*
    Context:
    A common mistake in C is thinking that passing an array to a function passes the whole array.
    It doesn't! It passes a *pointer* to the first element.
    This means `sizeof(array)` inside a function returns the size of the pointer (usually 8 bytes),
    not the size of the array data. To fix this, you must pass the size explicitly.
*/

#include <stdio.h>

// I AM NOT DONE

// TODO: Fix this function. It prints the wrong size because `arr` has decayed to a pointer.
// Change the function signature to accept `size_t length` as a second argument.
void print_array_size(int arr[]) {
    // Note: sizeof(arr) here returns sizeof(int*) which is 8 on 64-bit systems.
    // We want to print the number of elements.

    // printf("Elements in function: %zu\n", sizeof(arr) / sizeof(int)); // THIS IS WRONG!

    // Instead, print the passed length:
    printf("Elements in function: %zu\n", 0UL); // Replace 0UL with the length argument
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};

    // In main, sizeof works because the compiler knows `numbers` is an array of 5 ints.
    size_t length = sizeof(numbers) / sizeof(int);
    printf("Elements in main: %zu\n", length);

    // TODO: Update the function call to pass `length`.
    print_array_size(numbers);

    return 0;
}
