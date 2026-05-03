// Write a program to copy elements from one stack to another.
#include <stdio.h>

#define MAX 100

int stack1[MAX], stack2[MAX], temp[MAX];
int top1 = -1, top2 = -1, topTemp = -1;

// push functions
void push1(int val) {
    stack1[++top1] = val;
}

void push2(int val) {
    stack2[++top2] = val;
}

void pushTemp(int val) {
    temp[++topTemp] = val;
}

// pop functions
int pop1() {
    return stack1[top1--];
}

int popTemp() {
    return temp[topTemp--];
}

int main() {
    int n, val, i;

    printf("How many elements in stack 1? ");
    scanf("%d", &n);

    printf("Enter elements for stack 1: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        push1(val);
    }

    // to keep the same order, we use a temporary stack
    // Step 1: Pop from stack1 and push to temp
    while (top1 != -1) {
        pushTemp(pop1());
    }

    // Step 2: Pop from temp and push to stack2
    while (topTemp != -1) {
        push2(popTemp());
    }

    printf("Elements copied to stack 2 successfully!\n");
    printf("Stack 2 elements are: ");
    for (i = 0; i <= top2; i++) {
        printf("%d ", stack2[i]);
    }
    printf("\n");

    return 0;
}
