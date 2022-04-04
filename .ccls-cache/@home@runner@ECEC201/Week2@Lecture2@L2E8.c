#include <stdio.h>
int main()
{
  int foo=1000;
  while(foo!=1)
    {
      if(foo%2)
        foo+=1;
        foo=foo/2;
      printf("%i ",foo);
      }
  printf("\n");
}