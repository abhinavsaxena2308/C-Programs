//WAP to find the sum and average of elements in a 2D-array
#include <stdio.h>

int main() {
    int a[10][10], r, c, i, j;
    int sum = 0;
    float average;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 1. Calculate the total sum
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            sum = sum + a[i][j];
        }
    }

    // 2. Calculate the average
    // We use (float) to make sure the division gives us decimals
    average = (float)sum / (r * c);

    printf("\nTotal Sum: %d", sum);
    printf("\nAverage: %.2f", average);

    return 0;
}