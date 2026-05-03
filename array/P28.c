// WAP to find the sum of upper triangular elements of a matrix
#include <stdio.h>

int main() {
    int mat[10][10], n, i, j, sum = 0;

    printf("Enter order of square matrix (n): ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Logic: Upper triangular elements are where column index >= row index (j >= i)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j >= i) {
                sum += mat[i][j];
            }
        }
    }

    printf("Sum of upper triangular elements = %d\n", sum);

    return 0;
}
