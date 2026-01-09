// Learning Goal: Allocate memory for a single integer.
#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    // TODO: Use malloc to allocate memory for an integer
    int *p = NULL;

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 42;
    printf("Value: %d\n", *p);

    // Don't forget to free the memory!
    free(p);
    return 0;
}
