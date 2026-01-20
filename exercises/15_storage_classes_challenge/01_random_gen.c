// Learning Goal: Use static local variables to maintain state across function calls.
/*
    Context:
    A pseudo-random number generator (PRNG) needs to remember the last number it generated
    to calculate the next one. A `static` local variable is perfect for this because
    it keeps its value between function calls but is hidden from the rest of the program.
*/

#include <stdio.h>

// I AM NOT DONE

// Parameters for a simple Linear Congruential Generator (LCG)
#define A 1103515245
#define C 12345
#define M 2147483648

int next_random() {
    // TODO: define a static variable 'state' initialized to a seed (e.g., 123).
    // static unsigned int state = 123;

    // TODO: Calculate the next state using the formula: state = (state * A + C) % M;
    //       Note: Use 'unsigned int' for the math to match typical LCG implementations.

    // TODO: Update the static variable and return the result (cast to int).
    return 0;
}

int main() {
    printf("Random numbers:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", next_random());
    }
    return 0;
}
