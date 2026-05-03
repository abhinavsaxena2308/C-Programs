// Write a program to reverse a queue without using another queue.
#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

// simple enqueue
void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

// simple dequeue
int dequeue() {
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

// recursive function to reverse the queue
void reverseQueue() {
    // base case: if queue is empty
    if (front == -1) {
        return;
    }

    // dequeue the front element
    int data = dequeue();

    // recursively call for rest of the queue
    reverseQueue();

    // enqueue the element back (will be in reverse order)
    enqueue(data);
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original Queue: ");
    display();

    // calling the recursive reverse function
    reverseQueue();

    printf("Reversed Queue: ");
    display();

    return 0;
}
