// Learning Goal: Understand the importance of freeing memory.
#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    int *data = (int *)malloc(100 * sizeof(int));

    if (data == NULL) {
        return 1;
    }

    // Work with data...
    data[0] = 100;

    // TODO: Free the allocated memory to avoid a memory leak

    return 0;
}
