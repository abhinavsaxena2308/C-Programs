#include <stdio.h>

#define MAX 10
//Simulate Round Robin CPU Scheduling using queue.
// structure for process
struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

struct Process queue[MAX];
int front = -1, rear = -1;

// queue functions
void enqueue(struct Process p) {
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = p;
}

struct Process dequeue() {
    struct Process p = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return p;
}

int main() {
    int n, quantum, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++) {
        struct Process p;
        p.id = i + 1;
        printf("Enter burst time for P%d: ", p.id);
        scanf("%d", &p.burst_time);
        p.remaining_time = p.burst_time;
        enqueue(p);
    }

    printf("\nRound Robin Scheduling Simulation:\n");
    while (front != -1) {
        struct Process p = dequeue();
        
        if (p.remaining_time > quantum) {
            printf("Process P%d executed for %dms\n", p.id, quantum);
            p.remaining_time -= quantum;
            enqueue(p); // add back to queue
        } else {
            printf("Process P%d executed for %dms and Finished!\n", p.id, p.remaining_time);
            p.remaining_time = 0;
        }
    }

    return 0;
}
