// 12. For a given K value ( K > 0) reverse blocks of K nodes in a list.
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* reverseK(struct node* head, int k) {
    struct node *current = head, *next = NULL, *prev = NULL;
    int count = 0;
    
    // Reverse first k nodes
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    // next is now a pointer to (k+1)th node
    if (next != NULL) {
        head->next = reverseK(next, k);
    }
    
    return prev; // prev is the new head of this block
}

int main() {
    struct node* head = NULL;
    for (int i = 1; i <= 10; i++) {
        head = insertEnd(head, i);
    }

    int k = 3;
    printf("Original List: ");
    display(head);

    head = reverseK(head, k);

    printf("List after reversing in blocks of %d: ", k);
    display(head);

    return 0;
}
