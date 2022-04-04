/* Homework 2: Question 4
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q4 Q4.c
   Then run your compiled program with: ./Q4
*/
#include <stdio.h>

int main()
{
    int num, digits, temp;
    
    digits = 0;

    /* Get number from user */
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1){
        return -1;
    }

    if (num < 0){
        printf("Error: Input overflowed 32bit int\n");
        return -1;
    }
    /* Set the temp value to the number given */
    temp = num;
    do {
        /* Divide temp number by 10 */
        temp /= 10;
        /* Increment digit counter */
        digits++;
    /* Repeat DO block until temp/10 returns 0 */
    }while ( temp > 0 );

    /* Print results */
    printf("The number %d has %d digits\n", num, digits);

    return 0;
}