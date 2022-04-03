/* Homework 2: Question 2
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q2 Q2.c
   Then run your compiled program with: ./Q2
*/
#include <stdio.h>

int main()
{
    int income;
    float tax;

    printf("Enter your income (USD): ");
    // Scan keyboard and handle return value
    if (scanf("%d", &income) != 1){
        // Error if exepected return value
        return -1;
    }

    // $0 to $749
    if (income < 750){
        tax = 0.01*income;
    }
    // $750 to $2250
    else if (income < 2251){
        tax = 7.50 + 0.02*(income-750);
    }
    // $2251 to $3750
    else if (income < 3751){
        tax = 37.50 + 0.03*(income-2250);
    }
    // $3751 to $5250
    else if (income < 5251){
        tax = 82.50 + 0.04*(income-3750);
    }
    // $5251 to 7000
    else if (income < 7001){
        tax = 142.50 + 0.05*(income-5250);
    }
    // Over $7000
    else{
        tax = 230.0 + 0.06*(income-7000);
    }

    // Print results
    printf("Tax due: $%.2f\n",tax);

  return 0;
}