// Learning Goal: Learn how to resize dynamically allocated memory using realloc.
/*
    Context:
    Imagine you rented a storage unit, but now you have more stuff than will fit.
    You need a bigger unit! In C, `realloc` helps you do exactly that with memory.
    It tries to resize your existing memory block, or if it can't, it finds a new, larger spot,
    moves all your data there, and handles the cleanup of the old spot.
*/
//
// Syntax: void* realloc(void* ptr, size_t size);
// It returns a pointer to the new memory block (which might be the same or different).
// Always update your pointer variable with the result of realloc!

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    int *arr = (int*)malloc(2 * sizeof(int));
    if (arr == NULL) return 1;

    arr[0] = 10;
    arr[1] = 20;

    // We need to store 3 integers now!
    // TODO: Use realloc to resize 'arr' to hold 3 integers.
    // arr = ...

    // (This part is to verify your work works)
    arr[2] = 30;

    printf("Values: %d, %d, %d\n", arr[0], arr[1], arr[2]);

    free(arr);
    return 0;
}
