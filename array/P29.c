//pattern
#include <stdio.h>

int main() {
   int i, j, rows;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   for (i = 1; i <= rows; ++i) {
      // 1. Loop to print leading spaces (underscores)
      for (j = 1; j <= rows - i; ++j) {
         printf(" "); // Use "_" here if you want literal underscores
      }

      // 2. Loop to print numbers in descending order
      for (j = i; j >= 1; --j) {
         printf("%d", j);
      }

      // Move to the next line
      printf("\n");
   }

   return 0;
}