//11. WAP to count and display the position of Armstrong number in an array
#include <stdio.h>

int main() {
    int numbers[100], size, i;

    // 1. Ask the user how many numbers they want to check
    printf("How many numbers are in your list? ");
    scanf("%d", &size);

    // 2. Get the numbers from the user
    printf("Enter your numbers:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("\nResults:\n");

    // 3. Look at each number one by one
    for (i = 0; i < size; i++) {
        int currentNum = numbers[i];
        int sum = 0;
        int temp = currentNum;

        // The "Magic Check": Split the number into digits
        while (temp > 0) {
            int digit = temp % 10;           // Get the last digit
            sum = sum + (digit * digit * digit); // Cube it and add to sum
            temp = temp / 10;                // Remove the last digit
        }

        // 4. Compare the result
        if (sum == currentNum) {
            printf("Found %d at position %d\n", currentNum, i);
        }
    }

    return 0;
}