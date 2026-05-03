// Implement stack using two queues.
#include <stdio.h>

#define MAX 10

int q1[MAX], q2[MAX];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

// queue 1 operations
void pushQ1(int val) {
    if (f1 == -1) f1 = 0;
    q1[++r1] = val;
}

int popQ1() {
    int val = q1[f1];
    if (f1 == r1) f1 = r1 = -1;
    else f1++;
    return val;
}

// queue 2 operations
void pushQ2(int val) {
    if (f2 == -1) f2 = 0;
    q2[++r2] = val;
}

int popQ2() {
    int val = q2[f2];
    if (f2 == r2) f2 = r2 = -1;
    else f2++;
    return val;
}

// stack push: O(n) method to keep pop at O(1)
void push(int val) {
    // 1. push to empty q2
    pushQ2(val);

    // 2. move all from q1 to q2
    while (f1 != -1) {
        pushQ2(popQ1());
    }

    // 3. swap q1 and q2 (move everything back to q1)
    while (f2 != -1) {
        pushQ1(popQ2());
    }
    printf("Pushed %d onto stack\n", val);
}

// stack pop
void pop() {
    if (f1 == -1) {
        printf("Stack Empty!\n");
        return;
    }
    printf("Popped %d from stack\n", popQ1());
}

int main() {
    push(10);
    push(20);
    push(30);

    pop();
    pop();

    push(40);

    pop();
    pop();
    pop();

    return 0;
}
