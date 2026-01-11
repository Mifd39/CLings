// Learning Goal: Build a Virtual CPU to execute a custom bytecode.
/*
    Context:
    This is your final capstone project!
    You will build a Virtual CPU that can execute a simple set of instructions.

    The CPU has:
    - A Stack (array of integers)
    - A Stack Pointer (index of the top of the stack)
    - An Instruction Pointer (current instruction index)
    - A Program (array of instructions)

    Instruction Set:
    0: HALT  - Stop execution
    1: PUSH  - Push the next value in the program onto the stack
    2: ADD   - Pop two values, add them, push the result
    3: SUB   - Pop two values (b, a), result = a - b, push result
    4: PRINT - Pop the top value and print it

    Input Format:
    The input is a sequence of integers representing the program code.
    Example: 1 10 1 20 2 4 0
    - PUSH 10
    - PUSH 20
    - ADD (10 + 20 = 30)
    - PRINT (Output: 30)
    - HALT
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 128
#define MAX_PROGRAM 256

// I AM NOT DONE

// TODO: Define the Opcode enum
// typedef enum {
//     HALT = 0,
//     PUSH = 1,
//     ADD = 2,
//     SUB = 3,
//     PRINT = 4
// } Opcode;

// TODO: Define the CPU struct (stack, sp, ip, program memory)


// TODO: Implement the fetch-decode-execute cycle


int main() {
    // 1. Read the program from input (integers)

    // 2. Initialize the CPU

    // 3. Run the CPU loop until HALT

    return 0;
}
