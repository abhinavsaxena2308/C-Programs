//Write a program to reverse a string using a stack.
#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;
// simple push
void push(char c) {
    stack[++top] = c;
}
// simple pop
char pop() {
    return stack[top--];
}
int main() {
    char str[100];
    int i, len;
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    len = strlen(str);\
    // pushing each character onto stack
    for (i = 0; i < len; i++) {
        push(str[i]);
    }
    // popping characters back into the string
    for (i = 0; i < len; i++) {
        str[i] = pop();
    }
    printf("Reversed string is: %s\n", str);
    return 0;
}
