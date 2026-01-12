// Learning Goal: Understand Pointer Arithmetic.
/*
    Context:
    Pointers are more than just static addresses. You can do math with them!
    If you have a pointer to a list of numbers, adding 1 to the pointer moves it to the NEXT number in the list.
    The compiler is smart enough to know how big the numbers are (4 bytes for an int) and jumps the correct distance.
*/
//
// You can perform arithmetic on pointers to move them through memory.
// ptr++ moves the pointer to the NEXT element of that type.
// If ptr is an int*, ptr++ moves forward by sizeof(int) bytes.

#include <stdio.h>

// I AM NOT DONE

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;

    // TODO: Retrieve the 3rd element (30) using only pointer arithmetic (no array indexing).
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
