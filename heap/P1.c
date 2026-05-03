// Implement Max Heap using arrays and perform: Insert, DeleteMax, Heapify.
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Heapify function (Bottom-up adjustment)
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// 2. Insert operation
void insert(int val) {
    if (size == MAX) {
        printf("Heap Overflow!\n");
        return;
    }

    // Insert at the end
    heap[size] = val;
    int i = size;
    size++;

    // Bubble up to maintain max heap property
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("Inserted %d into Heap\n", val);
}

// 3. DeleteMax (extract root)
int deleteMax() {
    if (size <= 0) {
        printf("Heap Underflow!\n");
        return -1;
    }
    if (size == 1) {
        size--;
        return heap[0];
    }

    int root = heap[0];
    // move last element to root
    heap[0] = heap[size - 1];
    size--;

    // restore heap property from root
    heapify(0);

    return root;
}

void printHeap() {
    printf("Current Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(5);
    insert(15);

    printHeap();

    printf("Deleted Max: %d\n", deleteMax());
    printHeap();

    printf("Deleted Max: %d\n", deleteMax());
    printHeap();

    return 0;
}
