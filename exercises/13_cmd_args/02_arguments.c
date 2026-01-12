// Learning Goal: Access specific command line arguments.
/*
    Context:
    The 'argv' array stores all arguments as strings.
    argv[0] is always the program name.
    argv[1] is the first argument provided by the user, argv[2] is the second, and so on.
    Always check 'argc' before accessing argv to avoid crashing!
*/
//
// Loop through and print all arguments provided to the program.
//

#include <stdio.h>

// I AM NOT DONE

int main(int argc, char *argv[]) {
    // TODO: Print every argument passed to the program (skipping the program name).
    // Format: "Argument %d: %s\n"

    if (argc < 2) {
        printf("No arguments provided (besides program name).\n");
    }

    // Your loop here:

    return 0;
}
