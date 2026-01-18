// Learning Goal: Structure a simple test suite.
/*
    Context:
    A "Test Suite" is a collection of test cases.
    It's good practice to separate tests into different functions and run them all.
    We often track how many tests failed.
*/

#include <stdio.h>

// I AM NOT DONE

int multiply(int a, int b) {
    return a * b;
}

// Global failure counter
int failures = 0;

void assert_eq(int actual, int expected, const char *test_name) {
    if (actual != expected) {
        printf("FAIL: %s (Expected %d, got %d)\n", test_name, expected, actual);
        failures++;
    } else {
        printf("PASS: %s\n", test_name);
    }
}

void test_multiplication() {
    // TODO: Add at least 3 test cases for 'multiply' using assert_eq.
    // Ensure you test positive numbers, zero, and negative numbers.

    // To pass the verification, use these exact test cases:
    // 1. assert_eq(multiply(2, 3), 6, "multiply(2, 3) == 6");
    // 2. assert_eq(multiply(5, 0), 0, "multiply(5, 0) == 0");
    // 3. assert_eq(multiply(-1, 5), -5, "multiply(-1, 5) == -5");

}

int main() {
    printf("Running tests...\n");

    test_multiplication();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("%d tests failed.\n", failures);
    }

    return 0;
}
