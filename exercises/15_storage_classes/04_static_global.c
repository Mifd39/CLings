// Learning Goal: Understand internal linkage (static global variables).
/*
    Context:
    When you create a global variable, by default it can be accessed by *other* files
    using the 'extern' keyword. This is called "external linkage".

    Sometimes, you want a global variable that is shared by all functions in *this* file,
    but hidden from other files to prevent naming conflicts.
    You do this by adding the 'static' keyword to the global variable declaration.
    This gives it "internal linkage".
*/
//
// 1. Declare a static global integer 'secret_code' initialized to 1234.
// 2. Create a function 'check_secret' that prints "Access Granted" if the argument matches the secret.
//

#include <stdio.h>

// I AM NOT DONE

// TODO: Declare a static global variable 'secret_code' (int) initialized to 1234.


void check_secret(int guess) {
    // TODO: Check if guess matches secret_code.
    // If yes, print "Access Granted".
    // If no, print "Access Denied".

}

int main() {
    check_secret(0000);
    check_secret(1234);
    return 0;
}
