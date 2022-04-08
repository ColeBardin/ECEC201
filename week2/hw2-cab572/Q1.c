/* Homework 2: Question 1
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q1 Q1.c
   Then run your compiled program with: ./Q1
*/
#include <stdio.h>

int main()
{
    int scan_int, digit_count;

    printf("Enter a number: ");
    /* Scan from keyboard and error handle return value */
    if (scanf("%d", &scan_int) != 1) {
        /* Error if scanf does not find 1 match */
        return -1;
    }

    /* Inefficiently check input value */
    if (scan_int < 0){
        /* Error if value is overflown */
        return -2;
    }
    /* If value is less than 10 */
    else if (scan_int < 10){
        digit_count = 1;
    }
    /* If value is less than 100 */
    else if (scan_int < 100){
        digit_count = 2;
    }
    /* If value is less than 1000 */
    else if (scan_int < 1000){
        digit_count = 3;
    }
    /* If value is less than 10,000 */
    else if (scan_int < 10000){
        digit_count = 4;
    }
    /* Error if value is not negative and not less than 10,000 */  
    else{
        printf("ERROR: Invalid integer entered with more than 4 digits\n");
        return -3;
    }

    /* Print results */
    printf("The number %d has %d digits\n", scan_int, digit_count);
    
  return 0;
}

