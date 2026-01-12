// Learning Goal: Allocate memory for an array using malloc.
/*
    Context:
    What if you need an array, but you don't know how big it should be?
    Maybe you are reading a file, and it could have 10 lines or 10,000 lines.
    A standard array `int arr[10];` is fixed in size.
    With `malloc`, you can create an array of ANY size at runtime.
*/
//
// You can allocate a block of memory to act as an array.
// The size needed is: number_of_elements * sizeof(element_type).

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    int n = 5;
    // TODO: Allocate memory for an array of 'n' integers.
    int *arr = NULL;

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // You can access the memory just like a regular array.
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // TODO: Clean up.

    return 0;
}
