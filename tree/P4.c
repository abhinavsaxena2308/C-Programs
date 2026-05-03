// Give an algorithm for finding the level that has the maximum sum in the binary tree.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find the level with maximum sum
int findMaxSumLevel(struct node* root) {
    if (root == NULL) return 0;

    struct node* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;

    int max_sum = -1e9; // very small number
    int max_level = 0;
    int current_level = 0;

    while (front < rear) {
        int level_size = rear - front; // nodes at current level
        int current_sum = 0;
        current_level++;

        // process all nodes of current level
        for (int i = 0; i < level_size; i++) {
            struct node* temp = queue[front++];
            current_sum += temp->data;

            if (temp->left) queue[rear++] = temp->left;
            if (temp->right) queue[rear++] = temp->right;
        }

        // check if this level has higher sum
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_level = current_level;
        }
    }
    return max_level;
}

int main() {
    /*
            1        (Level 1, sum=1)
           / \
          10  3      (Level 2, sum=13)
         /  \
        4    5       (Level 3, sum=9)
    */
    struct node* root = newNode(1);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level with maximum sum is: %d\n", findMaxSumLevel(root));

    return 0;
}
