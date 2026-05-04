/* 
    EXPLANATION:
    Depth First Search (DFS) uses the Stack data structure because it follows 
    the LIFO (Last In First Out) principle. 

    How it works:
    1. We start from a source vertex and push it onto the stack.
    2. We pop the top vertex, mark it as visited, and then push all its 
       unvisited neighbors onto the stack.
    3. We repeat this until the stack is empty.
    
    This ensures that we go as deep as possible along each branch before 
    backtracking. Even recursive DFS uses the "Function Call Stack" internally!
*/

#include <stdio.h>

#define MAX 10
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

int main() {
    // Adjacency Matrix for a simple graph
    int adj[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    
    int visited[5] = {0, 0, 0, 0, 0};
    int i, v;

    printf("DFS Traversal starting from vertex 0: ");
    
    push(0); // Start from vertex 0

    while (top != -1) {
        v = pop();

        if (visited[v] == 0) {
            printf("%d ", v);
            visited[v] = 1;
        }

        // Push all unvisited neighbors to stack
        for (i = 4; i >= 0; i--) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                push(i);
            }
        }
    }
    printf("\n");

    return 0;
}
