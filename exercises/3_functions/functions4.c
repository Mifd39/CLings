// Learning Goal: Understand Recursion.
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
