// Learning Goal: Structure a simple test suite.
/*
    Context:
    A "Test Suite" is a collection of test cases.
    It's good practice to separate tests into different functions and run them all.
    We often track how many tests failed.
*/
//
// 1. Write a test function 'test_multiplication'.
// 2. Run it in main and track failures.
//

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
    // TODO: Call assert_eq to check if multiply(2, 3) is 6.


    // TODO: Call assert_eq to check if multiply(5, 0) is 0.


    // TODO: Call assert_eq to check if multiply(-1, 5) is -5.

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
