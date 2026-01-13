// Learning Goal: Understand Recursion.
/*
    Context:
    Sometimes, the best way to solve a problem is to break it down into a smaller version of the same problem.
    Recursion is a technique where a function calls itself.
    It's like looking into a mirror that reflects another mirror.
    To stop the infinite reflection, we need a "base case" — a condition where the function stops calling itself.
*/

#include <stdio.h>

// I AM NOT DONE

int factorial(int n) {
    // TODO: Implement the factorial function recursively.
    // Remember to handle the base case (0 or 1) and the recursive step.

    return 0; // Replace this
}

int main() {
    int result = factorial(5);

    printf("Factorial of 5 is: %d\n", result);

    if (result == 120) {
        printf("Recursion works!\n");
    } else {
        printf("Expected 120, got %d\n", result);
        return 1;
    }

    return 0;
}
