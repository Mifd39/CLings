// Learning Goal: Understand Bitwise Left Shift (<<) and Right Shift (>>) operators.
/*
    Context:
    Imagine shifting a row of soldiers to the left or right.
    In the binary world, shifting bits is a super-fast way to do math!
    - Shifting LEFT by 1 (<< 1) is like multiplying by 2.
    - Shifting RIGHT by 1 (>> 1) is like dividing by 2.
    It's one of the oldest tricks in the programmer's book.
*/
//
// << (Left Shift): Shifts bits to the left, filling with 0s. Equivalent to multiplying by powers of 2.
// >> (Right Shift): Shifts bits to the right. Equivalent to dividing by powers of 2 (for unsigned types).
//
// Example:
//   0001 (1) << 2 = 0100 (4)

#include <stdio.h>

// I AM NOT DONE

int main() {
    unsigned int number = 10; // Binary: ...0000 1010

    // TODO: Shift 'number' 1 bit to the left.
    // Hint: 10 * 2 = 20
    unsigned int left_shifted = 0;

    // TODO: Shift 'number' 1 bit to the right.
    // Hint: 10 / 2 = 5
    unsigned int right_shifted = 0;

    printf("10 << 1 = %u\n", left_shifted);
    printf("10 >> 1 = %u\n", right_shifted);

    if (left_shifted == 20 && right_shifted == 5) {
        printf("Shift operations correct!\n");
    } else {
        printf("Try again.\n");
        return 1;
    }

    return 0;
}
