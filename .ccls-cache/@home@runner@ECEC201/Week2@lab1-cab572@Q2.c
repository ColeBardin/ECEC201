#include <stdio.h>

int is_prime(int n)
{
  int d;

  for (d = 2; d < n; d++) {
    if (!(n % d))
      return 0;
  }

  return 1;
}

int main()
{
  if (is_prime(7))
    printf("Seven is Prime!\n");
  
  return 0;
}