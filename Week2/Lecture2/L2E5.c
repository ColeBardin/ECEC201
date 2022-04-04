//Modification of example on slide 56 of Lecture 2
#include <stdio.h>
int main()
{
  if(6>7)
    printf("\nFALSE!");
  if(6<7)
    printf("\nTRUE");
      if(6<=7)
        printf("\nALSO TRUE");
  if((6>7)||(6==7))
    printf("\nALSO FALSE");
  if (!(6>7))
    printf("\nALSO TRUE");
  return(0);
}