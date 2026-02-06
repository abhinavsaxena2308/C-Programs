// wap to find the transpose of a defined matrix in c
#include <stdio.h>  
int main() {
    int a[10][10], transpose[10][10];
    int r, c, i, j;

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

    // 3. Calculate transpose
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            transpose[j][i] = a[i][j];
        }
    }

    // 4. Print result
    printf("Transpose of the matrix:\n");
    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}