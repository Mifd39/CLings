// Learning Goal: Use bitwise operators to manage boolean flags.
/*
    Context:
    Instead of having 32 separate "boolean" variables, C programmers often pack 32 true/false flags into a single integer!
    Each bit represents a different option or permission.
    - Turn ON a flag: OR (|) with the flag.
    - Turn OFF a flag: AND (&) with the inverse (~). (Not covered here, but good to know)
    - Check a flag: AND (&) with the flag.
*/

#include <stdio.h>

// Definitions for our flags (powers of 2)
#define FLAG_HAS_ID     1  // 001
#define FLAG_IS_ACTIVE  2  // 010
#define FLAG_IS_ADMIN   4  // 100

// I AM NOT DONE

int main() {
    unsigned int user_status = 0;

    // TODO: Combine FLAG_HAS_ID and FLAG_IS_ACTIVE using the OR operator (|).
    // Assign the result to user_status.


    // TODO: Check if the user has the FLAG_IS_ADMIN property.
    // Use the AND operator (&) with FLAG_IS_ADMIN.
    int is_admin = 0; // Should be 0 (false) because we didn't add it.

    // TODO: Check if the user has the FLAG_IS_ACTIVE property.
    int is_active = 0;

    printf("User Status: %u\n", user_status);
    printf("Is Admin: %s\n", is_admin ? "Yes" : "No");
    printf("Is Active: %s\n", is_active ? "Yes" : "No");

    return 0;
}
