// Learning Goal: Understand global variables and their scope.
/*
    Context:
    A variable defined outside of any function is "global".
    It can be accessed and modified by any function in the file.
    Use them sparingly, as they make code harder to debug (anyone can change them!).
*/
//
// 1. Define a global integer variable 'counter' initialized to 0.
// 2. Modify it inside the 'increment' function.
// 3. Print it in 'main'.
//

#include <stdio.h>

// I AM NOT DONE

// TODO: Define a global variable 'counter' initialized to 0.


void increment() {
    // TODO: Increment the global 'counter'.

}

int main() {
    printf("Initial: %d\n", counter);
    increment();
    increment();
    printf("Final: %d\n", counter);
    return 0;
}
