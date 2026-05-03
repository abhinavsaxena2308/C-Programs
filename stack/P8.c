// Write a program to implement two stacks in a single array.
#include <stdio.h>

#define MAX 20

int arr[MAX];
int top1 = -1;
int top2 = MAX;

// push into stack 1 (starts from beginning)
void push1(int val) {
    if (top1 < top2 - 1) {
        arr[++top1] = val;
        printf("%d pushed to stack 1\n", val);
    } else {
        printf("Stack Overflow in Stack 1\n");
    }
}

// push into stack 2 (starts from end)
void push2(int val) {
    if (top1 < top2 - 1) {
        arr[--top2] = val;
        printf("%d pushed to stack 2\n", val);
    } else {
        printf("Stack Overflow in Stack 2\n");
    }
}

// pop from stack 1
void pop1() {
    if (top1 >= 0) {
        printf("Popped from stack 1: %d\n", arr[top1--]);
    } else {
        printf("Stack 1 Underflow\n");
    }
}

// pop from stack 2
void pop2() {
    if (top2 < MAX) {
        printf("Popped from stack 2: %d\n", arr[top2++]);
    } else {
        printf("Stack 2 Underflow\n");
    }
}

int main() {
    // testing stack 1
    push1(10);
    push1(20);
    
    // testing stack 2
    push2(100);
    push2(200);
    
    pop1();
    pop2();
    
    return 0;
}
