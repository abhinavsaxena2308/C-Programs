//Write a recursive program to find the nth Fibonacci number
#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the position (n) to find the Fibonacci number: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 0) {
        printf("Fibonacci sequence is not defined for negative indices.\n");
    } else {
        printf("The %d-th Fibonacci number is: %d\n", n, fibonacci(n));
    }

    return 0;
}
