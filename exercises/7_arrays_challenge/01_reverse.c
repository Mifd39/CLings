// Learning Goal: Manipulate arrays by modifying elements in place.
/*
    Context:
    Reversing an array is a classic algorithmic problem.
    You need to swap elements from the start and the end, moving towards the center.
    This requires careful indexing to avoid "off-by-one" errors.
*/

#include <stdio.h>

// I AM NOT DONE

void reverse_array(int arr[], int size) {
    // TODO: Swap elements to reverse the array in place.
    // Hint: Loop from 0 to size/2. Swap arr[i] with arr[size - 1 - i].

}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;

    reverse_array(numbers, size);

    printf("Reversed: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
