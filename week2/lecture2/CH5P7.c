#include <stdio.h>
int main()
{
      unsigned int n1,n2,n3,n4;
      unsigned int min,max;
      printf("\nEnter the 4 numbers separated by commas\n");
      scanf("%d,%d,%d,%d",&n1,&n2,&n3,&n4);
      min=n1;
      max=n1;
      if(n2<min) min=n2;
      else if(n2>max) max=n2;
      if(n3<min) min=n3;
      else if(n3>max) max=n3;
      if(n4<min) min=n4;
      else if(n4>max) max=n4;
      printf("\nMIN= %d , MAX=%d ",min,max);
      return(0);
}
