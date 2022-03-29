#include <stdio.h>
void foo(int grapes)
{
  int apples=4;
  printf("foo's apples: %d\n",apples);
  printf("foo's grapes: %d\n",grapes);
}
int main()
{
  int apples=10;
  int grapes=2;
  foo(grapes);
  printf("apples: %d\n", apples);
  printf("apples: %d\n", grapes);
  return(0);
}