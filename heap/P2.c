// Implement Min Heap and compare its behavior with Max Heap.
#include <stdio.h>

/*
    COMPARISON:
    1. Max Heap: The root contains the largest element. (Parent > Children)
    2. Min Heap: The root contains the smallest element. (Parent < Children)
    
    Logic Difference:
    - In Max Heap, we swap if child > parent.
    - In Min Heap, we swap if child < parent.
*/

#define MAX 100
int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify: ensures the smallest element is at root
void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

// Insert in Min Heap
void insert(int val) {
    if (size == MAX) return;

    heap[size] = val;
    int i = size;
    size++;

    // Bubble up: swap if current is smaller than parent
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract minimum element
int deleteMin() {
    if (size <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    minHeapify(0);
    return root;
}

void printHeap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    printf("Inserting 30, 10, 20, 5, 15 into Min Heap...\n");
    insert(30);
    insert(10);
    insert(20);
    insert(5);
    insert(15);

    printf("Min Heap Array: ");
    printHeap();

    printf("Smallest element (Root): %d\n", heap[0]);

    printf("Deleting smallest: %d\n", deleteMin());
    printf("Heap after deletion: ");
    printHeap();

    return 0;
}
