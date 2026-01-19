// Learning Goal: Analyze strings using loops and comparisons.
/*
    Context:
    A palindrome is a word, phrase, or sequence that reads the same backward as forward.
    Examples: "madam", "racecar", "level".

    You need to check if a given string is a palindrome.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// I AM NOT DONE

bool is_palindrome(char str[]) {
    // TODO: Return true if str is a palindrome, false otherwise.
    // Hint: Use strlen(str) to get the length.
    // Compare characters from the start and end moving inwards.

    return false;
}

int main() {
    char word1[] = "racecar";
    char word2[] = "hello";

    if (is_palindrome(word1)) {
        printf("%s is a palindrome.\n", word1);
    } else {
        printf("%s is NOT a palindrome.\n", word1);
    }

    if (is_palindrome(word2)) {
        printf("%s is a palindrome.\n", word2);
    } else {
        printf("%s is NOT a palindrome.\n", word2);
    }

    return 0;
}
