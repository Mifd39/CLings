// Learning Goal: Understand the importance of freeing memory.
//
// Every time you use 'malloc', you should have a corresponding 'free'.
// If you don't free memory, it stays occupied until your program ends (Memory Leak).
// In long-running programs, this can use up all available RAM!

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    // Allocating memory for 100 integers
    int *data = (int *)malloc(100 * sizeof(int));

    if (data == NULL) {
        return 1;
    }

    // Work with data...
    data[0] = 100;
    printf("Data allocated and used.\n");

    // TODO: Release the memory allocated for 'data'.


    return 0;
}
