// Learning Goal: Allocate memory for a single integer using malloc.
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
    // TODO: Use malloc to allocate memory for a single integer.
    // Use 'sizeof(int)' to get the correct size.
    int *p = NULL;

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 42;
    printf("Value: %d\n", *p);

    // It is good practice to free memory when you are done with it.
    free(p);
    return 0;
}
