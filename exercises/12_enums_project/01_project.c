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
    Example: 1 10 1 20 2 4 1 50 1 20 3 4 0
    - PUSH 10
    - PUSH 20
    - ADD (10 + 20 = 30)
    - PRINT (Output: 30)
    - PUSH 50
    - PUSH 20
    - SUB (50 - 20 = 30)
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

// TODO: Define the CPU struct
// typedef struct {
//     int stack[MAX_STACK];
//     int sp; // Stack Pointer (Top of stack index)
//     int program[MAX_PROGRAM];
//     int ip; // Instruction Pointer (Current instruction index)
// } CPU;


int main() {
    // 1. Read the program from input (stdin)
    int program_memory[MAX_PROGRAM];
    int program_size = 0;

    // Hint: Use scanf("%d", &val) in a loop until it returns EOF or 0.
    // Store values in program_memory and increment program_size.


    // 2. Initialize the CPU
    // CPU cpu;
    // cpu.sp = -1; // Start with empty stack
    // cpu.ip = 0;  // Start at beginning of program
    // TODO: Copy program_memory into cpu.program


    // 3. Run the CPU loop
    /*
    int running = 1;
    while (running) {
        // Fetch instruction: int opcode = cpu.program[cpu.ip];

        // Execute instruction
        switch (opcode) {
            case HALT:
                running = 0;
                break;
            case PUSH:
                // Note: The value to push is the *next* integer in the program.
                // Increment ip, read value, push to stack.
                break;
            case ADD:
                // Pop a, Pop b, Push a + b
                break;
            // ... Handle SUB and PRINT
        }

        // Advance Instruction Pointer (unless already moved by PUSH)
        cpu.ip++;
    }
    */

    return 0;
}
