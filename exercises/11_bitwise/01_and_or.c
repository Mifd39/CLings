// Learning Goal: Understand Bitwise AND (&) and OR (|) operators.
/*
    Context:
    Deep down, computers don't understand text or images; they only understand 0s and 1s.
    Sometimes, you need to work directly with these raw "bits".
    Think of a byte as a row of 8 light switches.
    - Bitwise AND (&) checks if TWO switches are BOTH on.
    - Bitwise OR (|) checks if AT LEAST ONE switch is on.
*/
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

    // TODO: Calculate the bitwise AND and OR of 'a' and 'b'.
    unsigned int and_result = 0;
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
