// 9. Write a program to search for an element in a linked list.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert(struct node* head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    return newNode;
}

void search(struct node* head, int key) {
    struct node* temp = head;
    int pos = 1, found = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        pos++;
        temp = temp->next;
    }
    if (!found) {
        printf("Element %d not found in the list\n", key);
    }
}

int main() {
    struct node* head = NULL;
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);

    printf("Searching for 20:\n");
    search(head, 20);
    
    printf("\nSearching for 50:\n");
    search(head, 50);

    return 0;
}
