#include <stdio.h>
int main()
{
float tax;
float income;
  char answer;
  while(1)
    {
printf("\nPress CTRL Z to stop. To continue enter income in $  ");
  scanf("%f",&income);
if(income<=750.0)
  tax= income/100.0;
  else if(income<=2250)
    tax=7.50+(income-750.0)/50.0;
    else if(income<=3750.0)
      tax=37.50 + (income-2250.0)*0.03;
      else if(income<=5250.0)
        tax=82.50+(income-3750.0)*0.04;
        else if(income<=7000.0)
          tax=142.50+(income-5250.0)*0.05;
            else
          tax=230.0+(income-7000.0)*0.06;
printf("Tax Payable=$ %.2f ",tax);
     
      }
return(0);
