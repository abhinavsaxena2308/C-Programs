// recursive function to reverse the string

#include <stdio.h>
#include <string.h>

void reverse(char str[], int start, int end) {
    char temp;
    if (start >= end) {
        return;
    }
    temp = str[start];  // swapping logic
    str[start] = str[end];
    str[end] = temp;
    reverse(str, start + 1, end - 1); // recursive call
}

int main() {
    char str[100];
    printf("Enter a string to reverse: ");
    scanf("%s", str);       // taking input
    int len = strlen(str);
    reverse(str, 0, len - 1);      //// calling the function
    printf("The reversed string is: %s\n", str);
    return 0;
}
