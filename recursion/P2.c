#include <stdio.h>
#include <string.h>

// recursive function to reverse the string
void reverse(char str[], int start, int end) {
    char temp;
    if (start >= end) {
        return;
    }

    // swapping logic
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // recursive call
    reverse(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Enter a string to reverse: ");
    scanf("%s", str); // taking input

    int len = strlen(str);

    // calling the function
    reverse(str, 0, len - 1);

    printf("The reversed string is: %s\n", str);

    return 0;
}
