// Learning Goal: Assign specific integer values to Enum constants.
/*
    Context:
    By default, Enums start counting at 0 and go up by 1 (0, 1, 2...).
    But sometimes you need them to match specific external values, like HTTP status codes (200, 404, 500) or error levels (1, 2, 4, 8).
    C lets you manually assign a value to any enum constant. Unassigned ones will just continue counting from the previous value.
*/

#include <stdio.h>

// I AM NOT DONE

typedef enum {
    // TODO: Assign specific values:
    // LOW = 10
    // MEDIUM = 50
    // HIGH = 100
    LOW,
    MEDIUM,
    HIGH
} Level;

int main() {
    Level current_level = MEDIUM;

    printf("Current Level Value: %d\n", current_level);

    if (current_level == 50) {
        printf("Level is correct!\n");
    } else {
        printf("Level is incorrect. Expected 50, got %d\n", current_level);
        return 1;
    }

    return 0;
}
