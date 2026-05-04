#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
int isFull() {
    if (rear == MAX - 1) {
        return 1; // true
    }
    return 0; // false
}
// function to check if queue is empty
int isEmpty() {
    if (front == -1 || front > rear) {
        return 1; // true
    }
    return 0; // false
}
int main() {
    // initially queue is empty
    if (isEmpty()) {
        printf("Initially: Queue is Empty\n");
    }

    // manually filling the queue for testing
    front = 0;
    rear = MAX - 1;
    if (isFull()) {
        printf("After filling: Queue is Full\n");
    }
    // empty it again
    front = -1;
    rear = -1;

    if (isEmpty()) {
        printf("After resetting: Queue is Empty again\n");
    }
    return 0;
}
