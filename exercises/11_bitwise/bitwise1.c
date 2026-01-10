// Learning Goal: Understand Bitwise AND (&) and OR (|) operators.
//
// Computers represent data as bits (0s and 1s).
// Bitwise operators allow you to manipulate these bits directly.
//
// & (AND): Result is 1 only if BOTH bits are 1.
// | (OR):  Result is 1 if AT LEAST ONE bit is 1.
//
// Example:
//   0101 (5)
// & 0011 (3)
// = 0001 (1)

#include <stdio.h>

// I AM NOT DONE

int main() {
    unsigned int a = 5; // Binary: 0101
    unsigned int b = 3; // Binary: 0011

    // TODO: Use the bitwise AND operator (&) to find the intersection of 'a' and 'b'.
    unsigned int and_result = 0;

    // TODO: Use the bitwise OR operator (|) to combine 'a' and 'b'.
    unsigned int or_result = 0;

    printf("a & b = %u\n", and_result);
    printf("a | b = %u\n", or_result);

    if (and_result == 1 && or_result == 7) {
        printf("Bitwise operations correct!\n");
    } else {
        printf("Try again.\n");
        return 1;
    }

    return 0;
}
