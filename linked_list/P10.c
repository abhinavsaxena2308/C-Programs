// 10. Split a Circular Linked List into two equal parts. If the number of nodes in the list are odd then make first list one node extra than second list.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertEnd(struct node* head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

void display(struct node* head) {
    if (head == NULL) return;
    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void splitList(struct node *head, struct node **head1, struct node **head2) {
    if (head == NULL) return;
    
    struct node *slow = head, *fast = head;
    
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // If there are even elements, fast->next->next is head
    if (fast->next->next == head) {
        fast = fast->next;
    }
    
    *head1 = head;
    
    if (head->next != head) {
        *head2 = slow->next;
    }
    
    fast->next = slow->next;
    slow->next = head;
}

int main() {
    struct node *head = NULL, *head1 = NULL, *head2 = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    printf("Original Circular List: ");
    display(head);

    splitList(head, &head1, &head2);

    printf("First Half: ");
    display(head1);
    
    printf("Second Half: ");
    display(head2);

    return 0;
}
