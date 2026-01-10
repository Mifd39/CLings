// Learning Goal: Combine conditionals, loops, and pointers to simulate a scoring system.
//
// This challenge tests your understanding of pointers and logic.

#include <stdio.h>

// I AM NOT DONE

/*
    Challenge 2: The Reference Logic

    You need to create a function `void update_score(int *score, int change)` that:
    1.  Accepts a pointer to the score and an integer value `change`.
    2.  If `change` is positive (> 0), it adds `change` to the `*score`.
    3.  If `change` is negative (< 0), it subtracts 10 from `*score` (a penalty), ignoring the actual magnitude of `change`.

    In the main function:
    1.  Initialize `score` to 100.
    2.  Create an array (simulated sequence) of changes: {10, -5, 20, -3, 5}.
    3.  Loop through these changes and call `update_score` for each change.
    4.  Print the final score using `printf` in the format: "Final score: %d\n"
*/

// TODO: Implement the 'update_score' function.


int main() {
    int score = 100;
    int changes[] = {10, -5, 20, -3, 5};
    int num_changes = 5; // The number of elements in the array

    // TODO: Process the changes array and update the score using your function.


    printf("Final score: %d\n", score);

    return 0;
}
