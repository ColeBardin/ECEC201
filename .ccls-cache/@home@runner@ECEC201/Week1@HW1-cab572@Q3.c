/* Homework 1: Question 3
   Compile with: gcc -o Q3 Q3.c
   Then run your compiled program with: ./Q3
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int num1, denom1, num3, denom3, result_num, result_denom;

    printf("Enter first fraction: ");
    if (scanf("%d / %d", &num1, &denom1) != 2){
        // Error handle return value of scanf()
        printf("ERROR: Scanf failed to match 2 items\n");
        return -1;
    }

    printf("Enter the second fraction: ");
    if (scanf("%d / %d", &num3, &denom3) != 2){
        // Error handle return value of scanf()
        printf("ERROR: Scanf failed to match 2 items\n");
        return -1;
    }

    result_num = num1 * denom3 + num3 * denom1;
    result_denom = denom1 * denom3;

    printf("The sum is %d/%d\n", result_num, result_denom);


    return 0;
}