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
    // TODO: Write a for loop that prints every argument.
    // Use the format: "Argument %d: %s\n"

    if (argc < 2) {
        printf("No arguments provided (besides program name).\n");
    }

    // Your loop here:
    // We start from 1 to skip the program name (argv[0])
    for (int i = 1; i < argc; i++) {

    }

    return 0;
}
