/* Homework 1: Question 4
   Compile with: gcc -o Q4 Q4.c
   Then run your compiled program with: ./Q4
*/

#include <stdio.h>

int main()
{
    int area_code, tele_prefix, line_num;
    
    printf("Enter phone number [(xxx) xxx-xxxx]:\t");

    if (scanf("(%d) %d - %d", &area_code, &tele_prefix, &line_num) != 3){
        // Error handle return value of scanf()
        printf("ERROR: Scanf failed to match 3 items\n");
        return -1;
    }

    printf("You entered %d.%d.%d\n", area_code, tele_prefix, line_num);

}