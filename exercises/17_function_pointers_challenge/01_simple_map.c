// Learning Goal: Implement a generic 'map' function using function pointers.
/*
    Context:
    'map' is a common higher-order function that applies a function to every
    element in a list, modifying the list in place (or returning a new one).

    In C, we can implement 'map' using a loop and a callback function.
*/
#include <stdio.h>

// I AM NOT DONE

// TODO: Define a function named 'map'.
// It should take:
// 1. An integer array
// 2. The size of the array (int)
// 3. A function pointer to a function that takes an int and returns an int.
//
// The 'map' function should apply the function pointer to each element of the array,
// replacing the old value with the new value returned by the function.

int double_it(int n) {
    return n * 2;
}

int negate_it(int n) {
    return -n;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Original: ");
    print_array(numbers, size);

    // TODO: Call 'map' with 'double_it' to double all numbers.

    printf("Doubled: ");
    print_array(numbers, size);

    // TODO: Call 'map' with 'negate_it' to negate all numbers.

    printf("Negated: ");
    print_array(numbers, size);

    return 0;
}
