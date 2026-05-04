//Write a program to evaluate a postfix expression using a stack.
#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

// stack functions
void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    char *e;
    int n1, n2, n3, num;

    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    e = exp;

    while (*e != '\0') {
        if (isdigit(*e)) {
            // if it's a number, push it (converting char to int)
            num = *e - '0';
            push(num);
        } else {
            // it's an operator, pop two numbers
            n1 = pop();
            n2 = pop();

            switch (*e) {
                case '+':
                    n3 = n2 + n1;
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '*':
                    n3 = n2 * n1;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
            }
            push(n3);
        }
        e++;
    }
    printf("The result of expression is: %d\n", pop());
    return 0;
}
