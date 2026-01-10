// Learning Goal: Allocate memory for an array using malloc.
//
// You can allocate a block of memory to act as an array.
// The size needed is: number_of_elements * sizeof(element_type).

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    int n = 5;
    // TODO: Use malloc to allocate memory for an array of 'n' integers and assign it to 'arr'.
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

    free(arr);
    return 0;
}
