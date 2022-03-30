/* Homework 1: Question 3
   Compile with: gcc -o Q3 Q3.c
   Then run your compiled program with: ./Q3
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char num1, denom1, num3, denom3, result_num, result_denom;

      printf("Enter first fraction: ");
      scanf("%s/%s", &num1, &denom1);

      printf("Enter the second fraction: ");
      scanf("%[^\n]/%[^\n]", &num3, &denom3);

      result_num = num1 * denom3 + num3 * denom1;
      result_denom = denom1 * denom3;

      printf("The sum is %d/%d\n", result_num, result_denom);

      return 0;
}