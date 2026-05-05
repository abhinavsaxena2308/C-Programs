// Implement Min Heap and compare its behavior with Max Heap.
#include <stdio.h>
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
    //swap if current is smaller than parent
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
    int n, val, choice;
    printf("Enter number of elements to insert into the min heap: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        insert(val);
    }
    printf("Min Heap Array: ");
    printHeap();
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert\n");
        printf("2. Delete Min\n");
        printf("3. Print Heap\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
        } else if (choice == 2) {
            int min = deleteMin();
            if (min != -1)
                printf("Deleted Min: %d\n", min);
        } else if (choice == 3) {
            printf("Min Heap Array: ");
            printHeap();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
