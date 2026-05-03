#include <stdio.h>
#include <stdlib.h>

// node structure
struct node {
    int data;
    struct node* next;
};

// create a new node
struct node* create(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to check for loop
int checkLoop(struct node* head) {
    struct node *s = head; // slow pointer
    struct node *f = head; // fast pointer

    while (s != NULL && f != NULL && f->next != NULL) {
        s = s->next;      // moves 1 step
        f = f->next->next; // moves 2 steps

        // if they meet, loop is there
        if (s == f) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct node* head = create(10);
    head->next = create(20);
    head->next->next = create(30);
    head->next->next->next = create(40);

    // making a loop: 40 points back to 20
    head->next->next->next->next = head->next;

    if (checkLoop(head)) {
        printf("Loop detected in the list!\n");
    } else {
        printf("No loop found.\n");
    }

    return 0;
}

