// Learning Goal: Combine Enums, Switch, and Bitwise operations.
//
// Challenge 4: State Machine
//
// You are building a simple state machine for a device.
// The device has states: IDLE, RUNNING, ERROR.
// It receives a command byte where:
// - Bit 0 (1): Start command
// - Bit 1 (2): Stop command
// - Bit 2 (4): Reset command

#include <stdio.h>

// I AM NOT DONE

typedef enum {
    IDLE,
    RUNNING,
    ERROR
} State;

// TODO: Implement the 'process_command' function.
// It takes the current 'state' and a 'command' (unsigned int).
// Rules:
// 1. If IDLE and Start bit is set -> Transition to RUNNING.
// 2. If RUNNING and Stop bit is set -> Transition to IDLE.
// 3. If any state and Reset bit is set -> Transition to IDLE.
// 4. Otherwise, stay in the same state.
// Return the new state.


int main() {
    State current_state = IDLE;

    // Test 1: Start
    current_state = process_command(current_state, 1); // Start
    if (current_state != RUNNING) {
        printf("Test 1 Failed: Expected RUNNING\n");
        return 1;
    }

    // Test 2: Stop
    current_state = process_command(current_state, 2); // Stop
    if (current_state != IDLE) {
        printf("Test 2 Failed: Expected IDLE\n");
        return 1;
    }

    // Test 3: Reset
    current_state = RUNNING;
    current_state = process_command(current_state, 4); // Reset
    if (current_state != IDLE) {
        printf("Test 3 Failed: Expected IDLE\n");
        return 1;
    }

    printf("Challenge 4 passed!\n");
    return 0;
}
