// Learning Goal: Understand how to declare and use arrays.
/*
    Context:
    Imagine you need to store the test scores of 30 students.
    Creating 30 separate variables (score1, score2, ..., score30) would be a nightmare to manage!
    Instead, C lets you group related variables of the same type into a single collection called an "array".
    It's like a row of mailboxes, all numbered and sitting next to each other.
*/
//
// An array is a collection of variables of the same type.
// Syntax: type name[size] = {value1, value2, ...};
//
// Example:
// int data[3] = {10, 20, 30};

#include <stdio.h>

// I AM NOT DONE

int main() {
    // TODO: Declare an array of integers named 'numbers' containing the values 1 through 5.


    int sum = 0;

    // TODO: Calculate the sum of all elements in the 'numbers' array.


    if (sum == 15) {
        printf("Sum is correct!\n");
    } else {
        printf("Sum is %d, expected 15.\n", sum);
    }

    return 0;
}
