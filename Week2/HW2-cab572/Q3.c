/* Homework 2: Question 3
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q3 Q3.c
   Then run your compiled program with: ./Q3
*/
#include <stdio.h>

int main()
{
    int days, start;

    // Get number of days of month from user
    printf("Enter number of days in month: ");
    // Handle scanf error
    if (scanf("%d", &days) != 1){
        return -1;
    }

    // Get starting day of week from user
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    // Hanld scanf error
    if (scanf("%d", &start) != 1){
        return -1;
    }

    // Print whitespace to set starting day of week
    for (int i = 0; i < start -1; i++){
        printf("\t");
    }

    // Print each day of the month
    for (int i = 0; i < days; i++){
        printf("%d", (i+1));
        if ((i+start) % 7 == 0){
            // If space is divisible by 7, add newline
            printf("\n");
        }
        else {
            // Else, print tab
            printf("\t");
        }
    }
    // Add extra newline after calendar is printed
    printf("\n");
    
    return 0;
}