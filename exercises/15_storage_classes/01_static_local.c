// Learning Goal: Understand the 'static' storage class for local variables.
/*
    Context:
    Normally, local variables are destroyed when a function returns.
    However, if you declare a local variable as 'static', it retains its value between function calls.
    It's initialized only once, the first time the function is called.
*/
//
// Create a function 'counter' that uses a static variable to count how many times it has been called.
//

#include <stdio.h>

// I AM NOT DONE

void counter() {
    // TODO: Define a static integer variable named 'count' initialized to 0.


    // TODO: Increment 'count'.


    printf("Count: %d\n", count);
}

int main() {
    counter(); // Should print "Count: 1"
    counter(); // Should print "Count: 2"
    counter(); // Should print "Count: 3"
    return 0;
}
