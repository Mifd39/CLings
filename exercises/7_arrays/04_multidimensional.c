// Learning Goal: Understand Multidimensional Arrays.
/*
    Context:
    Data isn't always a simple list. Sometimes it's a grid, like a spreadsheet or a chessboard.
    C handles this with "multidimensional arrays".
    A 2D array is essentially an "array of arrays".
    You access items using two coordinates: row and column.
*/

#include <stdio.h>

// I AM NOT DONE

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // TODO: Retrieve the value '6' from the matrix using its coordinates.
    int value = 0;


    printf("The value is: %d\n", value);

    if (value == 6) {
        printf("2D Array access correct!\n");
    } else {
        printf("Expected 6, got %d\n", value);
        return 1;
    }

    return 0;
}
