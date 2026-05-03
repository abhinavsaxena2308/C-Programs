//WAP to find the difference between two matrices
#include <stdio.h>
int main() {
    int a[10][10], b[10][10], diff[10][10];
    int r, c, i, j;

    // 1. Get size
    printf("Enter rows: ");
    scanf("%d", &r);
    printf("Enter cols: ");
    scanf("%d", &c);

    // 2. Get input for first matrix
    printf("Enter the elements of the first matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 3. Get input for second matrix
    printf("Enter the elements of the second matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // 4. Calculate difference of matrices
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            diff[i][j] = a[i][j] - b[i][j];
        }
    }

    // 5. Print the resulting difference matrix
    printf("Difference of the two matrices:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}