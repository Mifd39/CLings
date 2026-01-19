// Learning Goal: Apply complex logic conditions using nested if/else statements.
/*
    Context:
    Determining if a year is a leap year involves a specific set of rules.
    It's a perfect example of how real-world rules translate into logical conditions in code.

    Rule:
    A year is a leap year if:
    1. It is divisible by 4.
    2. BUT, if it is divisible by 100, it is NOT a leap year.
    3. UNLESS, it is also divisible by 400, then it IS a leap year.
*/

#include <stdio.h>
#include <stdbool.h>

// I AM NOT DONE

bool is_leap_year(int year) {
    // TODO: Implement the logic to return true if 'year' is a leap year, false otherwise.

    return false;
}

int main() {
    int year = 2000;

    if (is_leap_year(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    year = 1900;
    if (!is_leap_year(year)) {
        printf("%d is not a leap year.\n", year);
    } else {
        printf("%d is a leap year.\n", year);
    }

    year = 2024;
    if (is_leap_year(year)) {
        printf("%d is a leap year.\n", year);
    }

    return 0;
}
