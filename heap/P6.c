#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// node structure for the linked list in each bucket
struct Node {
    int data;
    struct Node* next;
};
// our hash table (array of Node pointers)
struct Node* chain[SIZE];
// hash function
int hash(int key) {
    return key % SIZE;
}
// function to insert into hash table
void insert(int key) {
    int index = hash(key);
    // create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;
    // Separate Chaining: Insert at the beginning of the list
    if (chain[index] == NULL) {
        chain[index] = newNode;
    } else {
        newNode->next = chain[index];
        chain[index] = newNode;
    }
}
// display the entire hash table
void display() {
    printf("\n--- Hash Table (Separate Chaining) ---\n");
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = chain[i];
        printf("Index %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // initialize all buckets to NULL
    for (int i = 0; i < SIZE; i++) {
        chain[i] = NULL;
    }

    // data to insert
    int data[] = {12, 22, 42, 17, 27};
    int n = 5;

    printf("Inserting values: 12, 22, 42, 17, 27\n");
    for (int i = 0; i < n; i++) {
        insert(data[i]);
    }

    display();

    return 0;
}
