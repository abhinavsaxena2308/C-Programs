// [ignoring loop detection]
// Implement a priority queue using: Array, Linked List, Heap. Compare performance.
#include <stdio.h>
#include <stdlib.h>

/*
    PERFORMANCE SUMMARY:
    - Array (Unsorted): Push is O(1), Pop is O(N) because we must search for the max element.
    - Linked List (Sorted): Push is O(N) to keep it sorted, Pop is O(1) from the head.
    - Binary Heap: Push is O(log N) and Pop is O(log N). This is the best overall balance.
*/

// --- 1. UNSORTED ARRAY ---
int q_arr[50], q_size = 0;
void arr_push(int val) { q_arr[q_size++] = val; }
int arr_pop() {
    int max_idx = 0;
    for (int i = 1; i < q_size; i++) if (q_arr[i] > q_arr[max_idx]) max_idx = i;
    int val = q_arr[max_idx];
    q_arr[max_idx] = q_arr[--q_size];
    return val;
}

// --- 2. SORTED LINKED LIST ---
struct Node { int data; struct Node* next; };
struct Node* list_head = NULL;
void list_push(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    if (list_head == NULL || val > list_head->data) {
        temp->next = list_head;
        list_head = temp;
    } else {
        struct Node* c = list_head;
        while (c->next != NULL && c->next->data > val) c = c->next;
        temp->next = c->next;
        c->next = temp;
    }
}
int list_pop() {
    struct Node* t = list_head;
    int v = t->data;
    list_head = list_head->next;
    free(t);
    return v;
}

// --- 3. MAX HEAP ---
int heap[50], heap_size = 0;
void heap_push(int val) {
    heap[heap_size] = val;
    int i = heap_size++;
    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        int t = heap[i]; heap[i] = heap[(i-1)/2]; heap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}
void heapify(int i) {
    int large = i, l = 2*i+1, r = 2*i+2;
    if (l < heap_size && heap[l] > heap[large]) large = l;
    if (r < heap_size && heap[r] > heap[large]) large = r;
    if (large != i) {
        int t = heap[i]; heap[i] = heap[large]; heap[large] = t;
        heapify(large);
    }
}
int heap_pop() {
    int v = heap[0];
    heap[0] = heap[--heap_size];
    heapify(0);
    return v;
}

int main() {
    int data[] = {10, 40, 20, 50, 30};
    for(int i=0; i<5; i++) {
        arr_push(data[i]);
        list_push(data[i]);
        heap_push(data[i]);
    }
    printf("Array Max: %d\n", arr_pop());
    printf("List Max: %d\n", list_pop());
    printf("Heap Max: %d\n", heap_pop());
    return 0;
}
