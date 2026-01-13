// Learning Goal: Understand Bitwise XOR (^) and Masks.
/*
    Context:
    The XOR (Exclusive OR) operator is a bit unique: it returns 1 only if the bits are DIFFERENT.
    It's incredibly useful for toggling things on and off (like a light switch) without needing to know their current state.
    We also use "masks" (specific patterns of 0s and 1s) to target and check specific bits, like checking if a security flag is set.
*/

#include <stdio.h>

// I AM NOT DONE

int main() {
    unsigned int flags = 5; // Binary: 0101 (Bits 0 and 2 are set)

    // TODO: Flip the 0th bit of 'flags' using XOR to toggle its state.
    unsigned int flipped = 0;

    // TODO: Check if the 2nd bit (value 4) is set using a mask and the AND operator.
    int is_bit_2_set = 0;


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
