// Learning Goal: Parse command line arguments to build a simple calculator.
/*
    Context:
    Many command-line tools (like git, docker, or cargo) accept "subcommands" and arguments.
    For example: `git commit -m "message"`.
    In this challenge, you will build a tiny calculator that accepts an operation
    and two numbers from the command line.
*/

#include <stdio.h>
#include <stdlib.h> // for atoi
#include <string.h> // for strcmp

// I AM NOT DONE

int main(int argc, char *argv[]) {
    // Expected usage: ./program <op> <num1> <num2>
    // Example: ./program add 10 20
    //          ./program sub 30 5
    //          ./program mul 5 5

    // TODO: 1. Check if argc is correct (needs 4 arguments: program name + 3 args).
    //          If not, print "Usage: <op> <num1> <num2>" and return 1.

    // TODO: 2. Parse the operation string (argv[1]).

    // TODO: 3. Parse the two numbers using atoi() (argv[2] and argv[3]).

    // TODO: 4. Perform the operation (add, sub, mul) and print the result.
    //          Format: "Result: <value>"
    //          If the operation is unknown, print "Unknown operation".

    return 0;
}
