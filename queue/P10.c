// Generate binary numbers from 1 to n using a queue.
#include <stdio.h>
#include <string.h>

#define MAX 100

// queue to store binary strings
char queue[MAX][50];
int front = -1, rear = -1;

void enqueue(char str[]) {
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    strcpy(queue[rear], str);
}

char* dequeue() {
    char* str = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return str;
}

int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    enqueue("1");

    printf("Binary numbers from 1 to %d:\n", n);
    for (i = 1; i <= n; i++) {
        char current[50], temp1[50], temp2[50];
        
        // get the front binary string
        strcpy(current, dequeue());
        printf("%s\n", current);

        // create next two binary strings
        strcpy(temp1, current);
        strcat(temp1, "0");
        enqueue(temp1);

        strcpy(temp2, current);
        strcat(temp2, "1");
        enqueue(temp2);
    }

    return 0;
}
