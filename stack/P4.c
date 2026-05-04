//Write a program to check balanced parentheses using a stack.
#include <stdio.h>
#include <string.h>
char stack[100];
int top = -1;
void push(char c) {         // stack functions
    stack[++top] = c;
}
char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}
// function to check balanced parentheses
int isBalanced(char exp[]) {
    int i;
    for (i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return 0; // stack empty means no opening bracket
            char last = pop();
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                return 0;}
        }
    }
    return (top == -1);     // if stack is empty, it's balanced                                              
}

int main() {
    char exp[100];

    printf("Enter an expression: ");
    scanf("%s", exp);

    if (isBalanced(exp)) {
        printf("The expression is Balanced.\n");
    } else {
        printf("The expression is Not Balanced.\n");
    }

    return 0;
}
