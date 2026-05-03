// 2. Write a program to detect a loop in a linked list.
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

int detectLoop(struct node* head) {
    struct node *slow = head, *fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; // loop found
        }
    }
    return 0; // no loop
}

int main() {
    struct node* head = NULL;
    head = insert(head, 20);
    head = insert(head, 4);
    head = insert(head, 15);
    head = insert(head, 10);

    // Create a loop for testing (10 -> 15 -> 4 -> 20 -> 15...)
    head->next->next->next->next = head->next;

    if (detectLoop(head)) {
        printf("Loop detected in the linked list!\n");
    } else {
        printf("No loop detected.\n");
    }

    return 0;
}
