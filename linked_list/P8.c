// 8. Write a program to count the number of nodes in a linked list.
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
int countNodes(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    struct node* head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    printf("Total number of nodes in the linked list: %d\n", countNodes(head));
    return 0;
}
