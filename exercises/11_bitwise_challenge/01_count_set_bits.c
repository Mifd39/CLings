// Learning Goal: Use bitwise operators to inspect integer representation.
/*
    Context:
    Counting the number of set bits (1s) in a binary number is a common operation.
    It's also known as "Hamming Weight".
    Example: 5 is 101 in binary, so it has 2 set bits.
*/

#include <stdio.h>

// I AM NOT DONE

int count_set_bits(unsigned int n) {
    int count = 0;
    // TODO: Count the number of '1's in the binary representation of n.
    // Hint: check the least significant bit with (n & 1), then right shift n (n >>= 1).
    // Repeat until n is 0.

    return count;
}

int main() {
    unsigned int num = 29; // Binary: 11101 (4 set bits)

    int bits = count_set_bits(num);

    printf("Number: %d\n", num);
    printf("Set bits: %d\n", bits);

    if (bits == 4) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. Expected 4.\n");
    }

    return 0;
}
