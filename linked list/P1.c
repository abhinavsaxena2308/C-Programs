// 1. Given two sorted Linked Lists, how to merge them into the third list in sorted order?
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert(struct node* head, int val) {
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

struct node* mergeLists(struct node* h1, struct node* h2) {
    struct node* dummy = (struct node*)malloc(sizeof(struct node));
    dummy->data = -1;
    dummy->next = NULL;
    struct node* temp = dummy;

    while (h1 != NULL && h2 != NULL) {
        if (h1->data < h2->data) {
            temp->next = h1;
            h1 = h1->next;
        } else {
            temp->next = h2;
            h2 = h2->next;
        }
        temp = temp->next;
    }
    
    if (h1 != NULL) temp->next = h1;
    if (h2 != NULL) temp->next = h2;

    return dummy->next;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    head1 = insert(head1, 10);
    head1 = insert(head1, 20);
    head1 = insert(head1, 40);

    head2 = insert(head2, 15);
    head2 = insert(head2, 25);
    head2 = insert(head2, 35);

    printf("List 1: "); display(head1);
    printf("List 2: "); display(head2);

    struct node* mergedHead = mergeLists(head1, head2);
    printf("Merged List: "); display(mergedHead);

    return 0;
}
