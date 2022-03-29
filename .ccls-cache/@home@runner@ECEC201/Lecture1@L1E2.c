#include <stdio.h>
int my_global = 10;
void foo()
{
  my_global=4;
  printf("%d\n",my_global);
  }
int main()
{
  foo();
  printf("%d\n",my_global);
  return(0);
}