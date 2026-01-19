// Learning Goal: Manage dynamic memory for a growing dataset.
/*
    Context:
    Standard arrays have a fixed size. What if you don't know how many items you'll have?
    You need a "dynamic array" that grows as needed.

    This exercise challenges you to use `malloc`, `realloc`, and `free` to store user input.
*/

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    int *numbers = NULL;
    int count = 0;
    int capacity = 0;
    int input;

    // printf("Enter numbers (enter -1 to stop):\n");

    while (1) {
        // TODO: Read an integer from the user.
        // If it's -1, break the loop.

        // TODO: If the array is full (count == capacity):
        // 1. Calculate new capacity (e.g., start with 2, then double it).
        // 2. Use realloc to resize 'numbers'.
        // 3. Check if realloc failed.

        // TODO: Store the input in the array and increment count.

        // For simulation purposes, we'll break manually if no logic is added
        break;
    }

    printf("You entered: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // TODO: Free the memory!

    return 0;
}
