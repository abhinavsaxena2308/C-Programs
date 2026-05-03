#include <stdio.h>
//Implement circular queue using arrays.
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// function to insert in circular queue
void enqueue(int val) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    printf("Inserted %d\n", val);
}

// function to delete from circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear) {
        // queue only had one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}
