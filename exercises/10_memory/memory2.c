// Learning Goal: Allocate memory for an array.
#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    int n = 5;
    // TODO: Use malloc to allocate memory for an array of 'n' integers
    int *arr = NULL;

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
