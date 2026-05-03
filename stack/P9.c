// Write a program to implement a stack that returns the minimum element in O(1) time.
#include <stdio.h>

#define MAX 100

int mainStack[MAX];
int minStack[MAX];
int top = -1;
int minTop = -1;

// push function
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    
    mainStack[++top] = val;

    // if minStack is empty or new value is smaller, push to minStack
    if (minTop == -1 || val <= minStack[minTop]) {
        minStack[++minTop] = val;
    }
}

// pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    // if the value being popped is the minimum, pop from minStack too
    if (mainStack[top] == minStack[minTop]) {
        minTop--;
    }
    top--;
}

// O(1) function to get minimum
int getMin() {
    if (minTop == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return minStack[minTop];
}

int main() {
    push(18);
    push(19);
    push(29);
    push(15);
    push(16);

    printf("Current Minimum: %d\n", getMin());
    
    pop(); // pop 16
    pop(); // pop 15
    
    printf("Current Minimum after pops: %d\n", getMin());

    return 0;
}
