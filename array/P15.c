//WAP to find the sum of even numbers in a 2D-array
#include <stdio.h>

int main() {
    int a[10][10], r, c, i, j;
    int sum = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    // 1. Input the 2D array
    printf("Enter the numbers:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 2. Loop and check for even numbers
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            
            if(a[i][j] % 2 == 0) { // Check if even
                sum = sum + a[i][j]; // Add only if even
            }
            
        }
    }

    // 3. Print result
    printf("Sum of even numbers: %d", sum);

    return 0;
}