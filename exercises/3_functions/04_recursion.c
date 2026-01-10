// Learning Goal: Understand Recursion.
/*
    Context:
    Sometimes, the best way to solve a problem is to break it down into a smaller version of the same problem.
    Recursion is a technique where a function calls itself.
    It's like looking into a mirror that reflects another mirror.
    To stop the infinite reflection, we need a "base case" — a condition where the function stops calling itself.
*/
//
// Recursion is when a function calls itself.
// It needs a "base case" to stop calling itself, otherwise it will run forever (Stack Overflow).
//
// Example: Factorial(n) = n * Factorial(n-1)

#include <stdio.h>

// I AM NOT DONE

int factorial(int n) {
    // TODO: Handle the base case. If n is 0 or 1, return 1.


    // TODO: Handle the recursive case. Return n * factorial(n - 1).

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
