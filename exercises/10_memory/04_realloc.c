// Learning Goal: Resize allocated memory using realloc.
/*
    Context:
    What if you used `malloc` to get some space, but later realized it wasn't enough?
    You could malloc a new, bigger block and copy everything... or you could use `realloc`.
    `realloc` tries to resize the existing memory block. If it can't, it finds a new spot, copies your data, and frees the old one automatically.
    It's like moving to a bigger house without packing boxes yourself!
*/

#include <stdio.h>
#include <stdlib.h>

// I AM NOT DONE

int main() {
    // Start with space for 2 integers
    int *numbers = (int*)malloc(2 * sizeof(int));
    if (numbers == NULL) return 1;

    numbers[0] = 10;
    numbers[1] = 20;

    // TODO: We need to store a 3rd number!
    // Use realloc to resize 'numbers' to hold 3 integers (3 * sizeof(int)).
    // Remember: realloc returns a pointer (which might be new), so assign it back to 'numbers'.


    if (numbers == NULL) { // realloc can fail too!
        printf("Realloc failed!\n");
        return 1;
    }

    // TODO: Set the 3rd element (index 2) to 30.


    printf("Numbers: %d, %d, %d\n", numbers[0], numbers[1], numbers[2]);

    free(numbers);
    return 0;
}
