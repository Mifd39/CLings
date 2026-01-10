// Learning Goal: Understand type casting.
/*
    Context:
    Sometimes you have data in one type (like an integer) but need to treat it as another (like a float).
    For example, if you divide 5 by 2 using integers, you get 2, not 2.5.
    "Casting" tells the compiler: "Treat this variable as this other type just for a moment."
    It allows for precise control over calculations.
*/

#include <stdio.h>

// I AM NOT DONE

int main() {
    int sum = 17;
    int count = 5;

    // TODO: Calculate the average.
    // Use an explicit cast (float) on 'sum' to ensure the division result is a decimal value.
    float average = 0.0;

    // TODO: Convert 'pi' to an integer to remove the decimal part.
    float pi = 3.14159;
    int integer_part = 0;

    printf("Average: %.1f\n", average);
    printf("Integer part of Pi: %d\n", integer_part);

    return 0;
}
