/* Homework 2: Question 3
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q3 Q3.c
   Then run your compiled program with: ./Q3
*/
#include <stdio.h>

int main()
{
    int days, start;

    printf("Enter number of days in month: ");
    if (scanf("%d", &days) != 1){
        return -1;
    }
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    if (scanf("%d", &start) != 1){
        return -1;
    }

    for (int i = 0; i < days + start - 1; i++){
        if (i < start){
            printf("\t");
        }
        else{
            printf("%d");
            if ( (i-1) % 7 == 0){
                printf("\n");
            }
            else{
                printf("\t");
            }
        }
    }
  return 0;
}