#include <stdio.h>
int main()
{
int x,y1,y2;
  
printf("\nEnter x ");
scanf("%d",&x);
y1=3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6;
  y2=((((3*x+2)*x-5)*x-1)*x+7)*x-6;
printf("\ny1=%d y2=%d",y1,y2);

return(0);
}
