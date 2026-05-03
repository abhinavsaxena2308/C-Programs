//WAP to the sum of middle row & column
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

    // 3. Calculate sum of middle row and column
    int midRow = r / 2;
    int midCol = c / 2;

    // Sum of middle row
    for(j = 0; j < c; j++) {
        sum += a[midRow][j];
    }

    // Sum of middle column (excluding the middle element to avoid double counting)
    for(i = 0; i < r; i++) {
        if(i != midRow) { // Skip the middle element
            sum += a[i][midCol];
        }
    }

    // 4. Print result
    printf("Sum of middle row and column: %d\n", sum);

    return 0;
}