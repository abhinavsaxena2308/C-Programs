// Write a program to find the largest element in a stack.
#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

// function to push elements
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Full\n");
        return;
    }   
    stack[++top] = val;
}

// function to find the largest element
int findLargest() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }

    int max = stack[0];
    for (int i = 1; i <= top; i++) {
        if (stack[i] > max) {
            max = stack[i];
        }
    }
    return max;
}

int main() {
    int n, i, val;

    printf("How many elements to push? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        push(val);
    }

    int largest = findLargest();
    if (largest != -1) {
        printf("The largest element in the stack is: %d\n", largest);
    }

    return 0;
}
