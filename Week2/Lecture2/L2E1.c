#include <stdio.h>
int main()
{
  for(int i=0;i<100;i++)
    printf("%d\n",i);
  return(0);
}
//Does not compile in c89;declare i separately
//Runs in c99 as is