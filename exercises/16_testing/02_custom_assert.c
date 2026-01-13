// Learning Goal: Create a custom assertion function.
/*
    Context:
    Sometimes 'assert()' is too harsh (it crashes).
    We might want to write a check that just prints "FAIL" but lets the program continue.
*/

#include <stdio.h>

// I AM NOT DONE

// TODO: Implement 'check_equals' to compare actual vs expected values.
// Print "PASS" if they match.
// Print "FAIL: Expected X, got Y" if they don't.
void check_equals(int actual, int expected) {

}

int main() {
    printf("Test 1: ");
    check_equals(1 + 1, 2); // Should PASS

    printf("Test 2: ");
    check_equals(2 * 2, 5); // Should FAIL

    return 0;
}
