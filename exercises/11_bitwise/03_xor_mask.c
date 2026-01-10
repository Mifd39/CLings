// Learning Goal: Understand Bitwise XOR (^) and Masks.
/*
    Context:
    The XOR (Exclusive OR) operator is a bit unique: it returns 1 only if the bits are DIFFERENT.
    It's incredibly useful for toggling things on and off (like a light switch) without needing to know their current state.
    We also use "masks" (specific patterns of 0s and 1s) to target and check specific bits, like checking if a security flag is set.
*/
//
// ^ (XOR): Result is 1 if bits are DIFFERENT, 0 if they are the SAME.
//   0101 (5)
// ^ 0011 (3)
// = 0110 (6)
//
// Masking: Using bitwise operators to isolate specific bits.
// To check if the 0th bit is set: (value & 1)

#include <stdio.h>

// I AM NOT DONE

int main() {
    unsigned int flags = 5; // Binary: 0101 (Bits 0 and 2 are set)

    // TODO: Use XOR (^) to flip the 0th bit of 'flags'.
    // Hint: XOR with 1 (0001) will flip the last bit.
    unsigned int flipped = 0;

    // TODO: Create a mask to check if the 2nd bit (value 4) is set.
    unsigned int mask = 4;
    int is_bit_2_set = 0;

    // Check if the 2nd bit is set in 'flags' using the mask and AND operator
    if (0) { // Replace 0 with condition
        is_bit_2_set = 1;
    }

    printf("Flipped: %u\n", flipped);
    printf("Is bit 2 set: %d\n", is_bit_2_set);

    if (flipped == 4 && is_bit_2_set == 1) {
        printf("XOR and masking correct!\n");
    } else {
        printf("Try again. Flipped: %u (expected 4), Bit 2 set: %d\n", flipped, is_bit_2_set);
        return 1;
    }

    return 0;
}
