#include <stdio.h>

// structure for a CPU process
struct Process {
    int pid;
    int burst_time;
    int priority;
};

#define MAX 20
struct Process heap[MAX];
int size = 0;

// function to swap two processes
void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// heapify based on priority (Max-Heap)
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].priority > heap[largest].priority)
        largest = left;

    if (right < size && heap[right].priority > heap[largest].priority)
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// insert process into priority queue
void insertProcess(int pid, int burst, int priority) {
    if (size == MAX) return;

    struct Process p;
    p.pid = pid;
    p.burst_time = burst;
    p.priority = priority;

    heap[size] = p;
    int i = size;
    size++;

    // bubble up based on priority
    while (i != 0 && heap[(i - 1) / 2].priority < heap[i].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// extract the process with highest priority
struct Process getNextProcess() {
    struct Process next = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
    return next;
}

int main() {
    // adding some jobs
    insertProcess(1, 10, 2); // PID 1, Burst 10, Priority 2
    insertProcess(2, 5, 5);  // PID 2, Burst 5, Priority 5 (High)
    insertProcess(3, 8, 1);  // PID 3, Burst 8, Priority 1 (Low)
    insertProcess(4, 4, 4);  // PID 4, Burst 4, Priority 4

    printf("CPU Job Scheduling Simulation (Highest Priority First):\n\n");
    printf("PID\tBurst Time\tPriority\n");
    printf("------------------------------------\n");

    while (size > 0) {
        struct Process current = getNextProcess();
        printf("%d\t%dms\t\t%d (Executing...)\n", current.pid, current.burst_time, current.priority);
    }

    return 0;
}
