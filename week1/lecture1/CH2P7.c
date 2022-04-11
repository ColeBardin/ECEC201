#include <stdio.h>
int main()
{
  int amount;
  int balance;
  int twenties,tens,fives,ones;
  char answer;
  while(1)
    {
      
  printf("\nEnter Amount:= ");
  scanf("%d",&amount);
  twenties=amount/20;
  balance=amount%20;
  tens=balance/10;
  balance=balance%10;
  fives=balance/5;
  ones=balance%5;
  printf("\nTwenties= %d,Tens= %d,Fives= %d, Ones= %d",twenties,tens,fives,ones);
  printf("\nHit CTRL Z to stop\n");   
  }
  return(0);
  }
