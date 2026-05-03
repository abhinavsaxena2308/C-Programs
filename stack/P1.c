#include <stdio.h>
#include <stdlib.h>

//Write a program to implement a stack using a linked list.
// structure for node
struct node {
    int data;
    struct node* next;
};

struct node* top = NULL; // global top pointer

// function to push element
void push(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    temp->data = val;
    temp->next = top;
    top = temp;
    printf("%d pushed to stack\n", val);
}

// function to pop element
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct node* temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}

// function to display stack
void display() {
    struct node* temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
