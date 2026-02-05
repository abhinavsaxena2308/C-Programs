//WAP to count the frequency of each element in a 2D-array
#include <stdio.h>

int main() {
    int a[10][10];       // The main matrix
    int visited[10][10]; // To keep track of counted numbers
    int r, c, i, j, k, l;
    int count;

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
            visited[i][j] = 0; // Mark everything as unvisited (0) initially
        }
    }

    printf("\nFrequency of elements:\n");
    
    // 3. Loop through every element
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            
            // If we already counted this number, skip it
            if(visited[i][j] == 1) {
                continue;
            }

            count = 0; // Reset count for the new number

            // 4. Check the whole array for matches
            for(k = 0; k < r; k++) {
                for(l = 0; l < c; l++) {
                    
                    if(a[i][j] == a[k][l]) {
                        count++;
                        visited[k][l] = 1; // Mark as visited so we don't count it again
                    }
                    
                }
            }

            // 5. Print the count for this number
            printf("%d appears %d times\n", a[i][j], count);
        }
    }

    return 0;
}