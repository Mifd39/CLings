// Learning Goal: Use 'else if' for multiple conditions.
//
// You can chain multiple conditions using 'else if'.
//
// if (condition1) {
//     // ...
// } else if (condition2) {
//     // ...
// } else {
//     // ...
// }

#include <stdio.h>

// I AM NOT DONE

int main() {
    int number = 10;

    if (number > 20) {
        printf("Number is greater than 20\n");
    }
    // TODO: Add an 'else if' block to check if number is greater than 5.
    // Since the previous 'if' checked > 20, this block effectively handles 5 < number <= 20.
    // Inside the block, print "Number is greater than 5\n".


    else {
        printf("Number is 5 or less\n");
    }

    return 0;
}
