//WAP to find max & min elements in a 2D-array
#include <stdio.h>

int main() {
    int a[10][10]; // A simplified fixed-size array
    int r, c, i, j;
    int max, min;

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

    // 3. Set initial values
    max = a[0][0];
    min = a[0][0];

    // 4. Find max and min
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(a[i][j] > max) {
                max = a[i][j];
            }
            if(a[i][j] < min) {
                min = a[i][j];
            }
        }
    }

    // 5. Print result
    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}