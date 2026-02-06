//WAP to the sum of diagonal elements
#include <stdio.h>
int main() {
    int a[10][10], r, c, i, j, sum = 0;

    // 1. Get size
    printf("Enter rows: ");
    scanf("%d", &r);
    printf("Enter cols: ");
    scanf("%d", &c);

    // 2. Get input
    printf("Enter the numbers:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 3. Calculate sum of diagonal elements
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(i == j) { // Check if it's a diagonal element
                sum += a[i][j];
            }
        }
    }

    // 4. Print result
    printf("Sum of diagonal elements: %d\n", sum);

    return 0;
}