// Learning Goal: Use loops to generate a sequence based on previous values.
/*
    Context:
    The Fibonacci sequence is a famous series of numbers where each number is the sum of the two preceding ones.
    It usually starts with 0 and 1.
    Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

    This challenges you to manage state (the previous two numbers) inside a loop.
*/

#include <stdio.h>

// I AM NOT DONE

int main() {
    int n = 10; // Generate first n numbers
    int t1 = 0, t2 = 1;
    int nextTerm;

    printf("Fibonacci Series: ");

    // TODO: Write a loop to print the first 'n' terms of the Fibonacci sequence.
    // Ensure you handle the first two terms (0 and 1) correctly.
    // The output should be comma-separated.
    // Example format: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34

    // Hint: Inside the loop, calculate nextTerm = t1 + t2; then update t1 and t2.

    printf("\n");

    return 0;
}
