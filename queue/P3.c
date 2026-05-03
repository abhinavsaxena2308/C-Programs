#include <stdio.h>
//Implement queue using two stacks.
#define MAX 10

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// simple push and pop for stacks
void push1(int val) {
    stack1[++top1] = val;
}

void push2(int val) {
    stack2[++top2] = val;
}

int pop1() {
    return stack1[top1--];
}

int pop2() {
    return stack2[top2--];
}

// enqueue: always push to stack 1
void enqueue(int val) {
    if (top1 == MAX - 1) {
        printf("Queue Full!\n");
        return;
    }
    push1(val);
    printf("Enqueued %d\n", val);
}

// dequeue: move elements from s1 to s2, then pop from s2
void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    // if stack2 is empty, move everything from stack1
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    printf("Dequeued %d\n", pop2());
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    enqueue(40);

    dequeue();
    dequeue();

    return 0;
}
