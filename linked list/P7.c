// 7. Write a program to remove duplicate elements from a linked list.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertEnd(struct node* head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    struct node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void removeDuplicates(struct node* head) {
    struct node *current = head, *temp, *duplicate;
    while (current != NULL && current->next != NULL) {
        temp = current;
        while (temp->next != NULL) {
            if (current->data == temp->next->data) {
                duplicate = temp->next;
                temp->next = temp->next->next;
                free(duplicate);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main() {
    struct node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 10);
    head = insertEnd(head, 30);
    head = insertEnd(head, 20);

    printf("Original List: ");
    display(head);

    removeDuplicates(head);

    printf("After removing duplicates: ");
    display(head);

    return 0;
}
