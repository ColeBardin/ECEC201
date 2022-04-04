/* Homework 1: Question 2
   Compile with: gcc -o Q2 Q2.c
   Then run your compiled program with: ./Q2
*/

#include <stdio.h>

int main()
{
    int x;
    
    printf("Please enter an integer value: ");
    if (scanf("%d", &x) != 1){
        // Error out of main if scanf does not successfully match 1 item
        return -1;
    }
    
    printf("%d\n", 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6);

    return 0;
}