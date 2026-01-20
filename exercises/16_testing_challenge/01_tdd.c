// Learning Goal: Implement functionality to pass an existing test suite.
/*
    Context:
    In Test-Driven Development (TDD), you write tests before you write the actual code.
    Here, the tests are provided for you. Your job is to implement the `is_prime`
    function so that all the tests pass.
*/

#include <stdio.h>
#include <stdbool.h>

// I AM NOT DONE

// TODO: Implement this function to pass the tests below.
//       Return true if n is prime, false otherwise.
//       Hints:
//       - Numbers <= 1 are not prime.
//       - Check divisibility from 2 up to n/2 (or i*i <= n).
bool is_prime(int n) {
    return false;
}

void run_tests() {
    // Test cases - DO NOT MODIFY
    printf("Running tests...\n");

    if (is_prime(2) == true) printf("PASS: 2 is prime\n");
    else printf("FAIL: 2 is prime\n");

    if (is_prime(4) == false) printf("PASS: 4 is not prime\n");
    else printf("FAIL: 4 is not prime\n");

    if (is_prime(13) == true) printf("PASS: 13 is prime\n");
    else printf("FAIL: 13 is prime\n");

    if (is_prime(1) == false) printf("PASS: 1 is not prime\n");
    else printf("FAIL: 1 is not prime\n");

    if (is_prime(15) == false) printf("PASS: 15 is not prime\n");
    else printf("FAIL: 15 is not prime\n");

    if (is_prime(17) == true) printf("PASS: 17 is prime\n");
    else printf("FAIL: 17 is prime\n");
}

int main() {
    run_tests();
    return 0;
}
