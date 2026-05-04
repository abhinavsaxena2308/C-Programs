// 6. Write a program to find the middle element of a linked list.
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

void findMiddle(struct node* head) {
    if (head == NULL) return;
    struct node *slow = head, *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element is: %d\n", slow->data);
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    head = insert(head, 50);
    head = insert(head, 40);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);

    printf("List: ");
    display(head);
    
    findMiddle(head);

    return 0;
}
