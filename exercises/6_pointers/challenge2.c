// Learning Goal: Combine conditionals, loops, and pointers to simulate a scoring system.
#include <stdio.h>

// I AM NOT DONE

/*
    Challenge 2: The Reference Logic

    You need to create a function `void update_score(int *score, int change)` that:
    1.  Accepts a pointer to the score and an integer value `change`.
    2.  If `change` is positive, it adds `change` to the `*score`.
    3.  If `change` is negative, it subtracts 10 from `*score` (a penalty), ignoring the actual value of `change`.

    In the main function:
    1.  Initialize `score` to 100.
    2.  Create an array (simulated sequence) of changes: {10, -5, 20, -3, 5}.
    3.  Loop through these changes and call `update_score`.
    4.  Print the final score using `printf` in the format: "Final score: %d\n"
*/

// TODO: Define update_score


int main() {
    int score = 100;
    int changes[] = {10, -5, 20, -3, 5};

    // TODO: Loop through changes and call update_score

    printf("Final score: %d\n", score);

    return 0;
}
