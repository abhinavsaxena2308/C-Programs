// 5. Write a program to reverse a linked list.
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

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* reverse(struct node* head) {
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    struct node* head = NULL;
    head = insert(head, 40);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);

    printf("Original List: ");
    display(head);

    head = reverse(head);

    printf("Reversed List: ");
    display(head);

    return 0;
}
