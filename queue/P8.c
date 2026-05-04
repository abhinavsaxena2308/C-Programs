// Reverse first K elements of a queue.
#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
// enqueue function
void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}
// dequeue function
int dequeue() {
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}
// function to reverse first K elements
void reverseFirstK(int k, int total) {
    if (k > total || k <= 0) return;
    int stack[MAX];
    int top = -1;
    // 1. dequeue first K and push to stack
    for (int i = 0; i < k; i++) {
        stack[++top] = dequeue();
    }
    // 2. pop from stack and enqueue back
    while (top != -1) {
        enqueue(stack[top--]);
    }
    // 3. move the remaining (total-k) elements to the end
    for (int i = 0; i < (total - k); i++) {
        enqueue(dequeue());
    }
}

void display() {
    if (front == -1) return;
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int k = 3;
    int n = 5;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("Original Queue: ");
    display();
    reverseFirstK(k, n);
    printf("Queue after reversing first %d elements: ", k);
    display();
    return 0;
}
