// Simulate a printer queue using queue operations.
#include <stdio.h>
#include <string.h>
#define MAX 5
char printer_queue[MAX][50];            // our queue stores job names (strings)
int front = -1, rear = -1;

// function to add a print job
void addJob(char job[]) {
    if (rear == MAX - 1) {
        printf("Printer Busy! Queue is full.\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    strcpy(printer_queue[rear], job);
    printf("Job '%s' added to printer queue.\n", job);
}
// function to process/print the next job
void printJob() {
    if (front == -1 || front > rear) {
        printf("No jobs to print.\n");
        return;
    }
    printf("Printing document: %s\n", printer_queue[front]);
    front++;
    // reset if all jobs are done
    if (front > rear) {
        front = rear = -1;
    }
}

// function to see waiting jobs
void showJobs() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\n--- Current Print Queue ---\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s\n", i - front + 1, printer_queue[i]);
    }
}
int main() {
    int choice;
    char jobName[50];
    while (1) {
        printf("\n--- Printer Simulation ---\n");
        printf("1. Add Job\n2. Print Next Job\n3. Show Waiting Jobs\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter document name (single word): ");
                scanf("%s", jobName);
                addJob(jobName);
                break;
            case 2:
                printJob();
                break;
            case 3:
                showJobs();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
