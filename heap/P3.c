// Write a program for Heap Sort and trace every pass. Input: 15, 10, 30, 40, 5
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// standard max-heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 1. Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    printf("Max Heap built: ");
    printArray(arr, n);
    printf("---------------------------\n");

    // 2. Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // move current root (max) to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);

        printf("Pass %d (max element %d moved to end): ", n - i, arr[i]);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {15, 10, 30, 40, 5};
    int n = 5;

    printf("Original Array: ");
    printArray(arr, n);
    printf("\n");

    heapSort(arr, n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    return 0;
}
