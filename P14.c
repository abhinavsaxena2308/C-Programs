//wap to find the sum of n numbers using array
#include <stdio.h>

int main() {
    int a[100], n, i;
    int sum = 0; // Always start sum at 0

    printf("How many numbers? ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Adding them up
    for(i = 0; i < n; i++) {
        sum = sum + a[i]; 
    }

    printf("Total sum = %d", sum);

    return 0;
}