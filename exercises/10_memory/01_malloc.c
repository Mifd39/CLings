// Learning Goal: Allocate memory for a single integer using malloc.
/*
    Context:
    Normally, variables are created automatically when you declare them.
    But sometimes you don't know if you need a variable until the program is already running.
    "Dynamic Memory Allocation" allows you to ask the computer for extra memory space on the fly.
    The function `malloc` (Memory Allocation) acts like a request form: "Please give me X bytes of space."
*/
//
// Dynamic memory allocation allows you to request memory from the heap at runtime.
// The `malloc` function returns a void pointer (void*), which we cast to the desired type.
//
// Syntax:
// type *ptr = (type *)malloc(size_in_bytes);
//
// Always include <stdlib.h> for malloc and free.

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    // TODO: Dynamically allocate memory for an integer pointer 'p'.
    int *p = NULL;

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 42;
    printf("Value: %d\n", *p);

    // TODO: Free the allocated memory.

    return 0;
}
