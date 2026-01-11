// Learning Goal: Understand how to convert between data types using casting.
/*
    Context:
    Sometimes you need to treat a variable as a different type for a specific operation.
    For example, if you divide two integers like 5 / 2, C performs "integer division" and gives you 2, throwing away the .5.
    To get the precise decimal result (2.5), you need to tell C to treat at least one of the numbers as a floating-point number.
    This explicit conversion is called "type casting".
*/
//
// To cast a variable to another type, put the target type in parentheses before the variable.
// Example: (float)my_int

#include <stdio.h>

// I AM NOT DONE

int main() {
    int a = 5;
    int b = 2;
    float result;

    // TODO: Modify the line below to cast 'a' (or 'b') to a float so that the result is 2.5.
    result = a / b;

    printf("The result is: %.1f\n", result);
    return 0;
}
