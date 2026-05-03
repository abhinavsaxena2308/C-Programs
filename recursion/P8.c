#include <stdio.h>
#include <string.h>

// recursive function to check if string is palindrome
int checkPalindrome(char str[], int start, int end) {
    // if start and end meet, it is a palindrome
    if (start >= end) {
        return 1;
    }
    // if characters don't match, not a palindrome
    if (str[start] != str[end]) {
        return 0;
    }
    // recursive call
    return checkPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    // calling the function
    if (checkPalindrome(str, 0, strlen(str) - 1)) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is NOT a palindrome.\n", str);
    }

    return 0;
}
