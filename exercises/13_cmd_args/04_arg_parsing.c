// Learning Goal: Parse command line flags manually.
/*
    Context:
    Command-line tools often accept flags like "-v" (verbose) or "-h" (help).
    Since 'argv' is just an array of strings, you can loop through it and compare strings.
*/
//
// Check if the "--verbose" flag is present in the arguments.
// If it is, set the 'verbose' variable to true (1).
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// I AM NOT DONE

int main(int argc, char *argv[]) {
    bool verbose = false;

    // TODO: Loop through all arguments (skip argv[0] which is the program name).
    for (int i = 1; i < argc; i++) {
        // TODO: Use strcmp to check if argv[i] is "--verbose".
        // Hint: strcmp returns 0 if strings are equal.
        if (false /* REPLACE THIS */) {
            verbose = true;
        }
    }

    if (verbose) {
        printf("Verbose mode enabled.\n");
    } else {
        printf("Standard mode.\n");
    }

    return 0;
}
