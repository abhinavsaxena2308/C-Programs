//Write a program to convert an infix expression to postfix.
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

// stack functions
void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// function to check operator priority
int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[100];
    char *e, x;

    printf("Enter the infix expression: ");
    scanf("%s", exp);
    e = exp;

    printf("Postfix expression: ");
    while (*e != '\0') {
        if (isalnum(*e)) {
            // if it's a number or letter, print it
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            // pop until '(' is found
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            // operator: check priority
            while (top != -1 && priority(stack[top]) >= priority(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    // pop remaining operators
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}
