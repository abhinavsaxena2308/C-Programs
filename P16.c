//WAP to print odd numbers in a 2D-array
#include <stdio.h>

int main() {
    int a[10][10], r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter the numbers:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nOdd numbers in the array are: ");
    
    // Loop through the 2D array
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            
            // If the number divided by 2 has a remainder NOT equal to 0
            if(a[i][j] % 2 != 0) { 
                printf("%d ", a[i][j]);
            }
            
        }
    }

    return 0;
}