// 11. How will you check if the linked list is palindrome or not?
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

// Check if linked list is a palindrome by copying to an array
int isPalindrome(struct node* head) {
    int arr[100], i = 0, j;
    struct node* temp = head;
    
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    
    for (j = 0; j < i / 2; j++) {
        if (arr[j] != arr[i - j - 1]) {
            return 0; // false
        }
    }
    return 1; // true
}

int main() {
    struct node* head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is NOT a palindrome.\n");
    }

    return 0;
}
