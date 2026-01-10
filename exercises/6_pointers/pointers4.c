// Learning Goal: Understand Pointer Arithmetic.
//
// You can perform arithmetic on pointers to move them through memory.
// ptr++ moves the pointer to the NEXT element of that type.
// If ptr is an int*, ptr++ moves forward by sizeof(int) bytes.

#include <stdio.h>

// I AM NOT DONE

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;

    // TODO: Use pointer arithmetic to access the 3rd element (30).
    // Hint: Add to 'ptr' and then dereference it.
    int third_value = 0;


    printf("The 3rd value is: %d\n", third_value);

    if (third_value == 30) {
        printf("Pointer arithmetic works!\n");
    } else {
        printf("Expected 30, got %d\n", third_value);
        return 1;
    }

    return 0;
}
