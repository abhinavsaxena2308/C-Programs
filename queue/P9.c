// Interleave first half of a queue with second half.
#include <stdio.h>

#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

// dequeue
int dequeue() {
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

// function to interleave
void interleave(int n) {
    int stack[MAX];
    int top = -1;
    int half = n / 2;

    // 1. Push first half into stack
    for (int i = 0; i < half; i++) {
        stack[++top] = dequeue();
    }

    // 2. Enqueue from stack back into queue
    while (top != -1) {
        enqueue(stack[top--]);
    }

    // 3. Dequeue first half and enqueue back
    for (int i = 0; i < half; i++) {
        enqueue(dequeue());
    }

    // 4. Push first half into stack again
    for (int i = 0; i < half; i++) {
        stack[++top] = dequeue();
    }

    // 5. Interleave
    while (top != -1) {
        enqueue(stack[top--]);
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
    int n = 4; // testing with 4 elements
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    printf("Original Queue: ");
    display();

    interleave(n);

    printf("Interleaved Queue: ");
    display();

    return 0;
}
