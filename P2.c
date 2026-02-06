//WAP to count the frequency of each element in a 2D-array

#include <stdio.h>
int main() {
    int a[10][10]; 
    int r, c, i, j, k, count;
    int freq[100] = {0}; 
    printf("enter rows: ");
    scanf("%d", &r);
    printf("enter cols: ");
    scanf("%d", &c);
    printf("enter the numbers:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            count = 1;
            for(k = j + 1; k < c; k++) {
                if(a[i][j] == a[i][k]) {
                    count++;
                    freq[a[i][j]]++; 
                }
            }
            if(freq[a[i][j]] == 0) { 
                freq[a[i][j]] = count; 
            }
        }
    }
    printf("element frequency\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(freq[a[i][j]] != -1) { 
                printf("%d\t%d\n", a[i][j], freq[a[i][j]]);
                freq[a[i][j]] = -1; 
            }
        }
    }

    return 0;
}