// Reverse an array
#include <stdio.h>

int main() {
    int a[100], n, i, temp;
    int start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize markers
    start = 0;
    end = n - 1;

    // Reversing logic
    while(start < end) {
        // Swap elements using a temporary variable
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        // Move markers toward the middle
        start++;
        end--;
    }

    printf("Reversed array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}