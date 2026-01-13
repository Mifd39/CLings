// Learning Goal: Correctly compare floating point numbers in tests.
/*
    Context:
    Comparing floating point numbers (float, double) with '==' is dangerous!
    Computers cannot store decimals like 0.1 perfectly precisely.
    So, 0.1 + 0.2 might equal 0.30000000000000004, which is not == 0.3.

    To test floats, we check if the difference between them is very small.
    This small allowed difference is called "EPSILON".
    Standard practice: if (fabs(a - b) < EPSILON) -> They are equal.
*/
//
// 1. Include <math.h> for fabs() (absolute value for floats).
// 2. Implement 'is_close' using an EPSILON of 0.0001.
// 3. Use it to check if 0.1 + 0.2 is "close enough" to 0.3.
//

#include <stdio.h>
#include <math.h>

// I AM NOT DONE

#define EPSILON 0.0001

int is_close(double a, double b) {
    // TODO: Return 1 (true) if the absolute difference between a and b is less than EPSILON.
    // Otherwise return 0 (false).

    return 0;
}

int main() {
    double result = 0.1 + 0.2;
    double expected = 0.3;

    printf("Direct comparison (==): %s\n", (result == expected) ? "Equal" : "Not Equal");

    // TODO: Use is_close to print the correct result.
    if (is_close(result, expected)) {
        printf("Epsilon comparison: Equal\n");
    } else {
        printf("Epsilon comparison: Not Equal\n");
    }

    return 0;
}
