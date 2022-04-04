#include <stdio.h>

int is_prime(int n)
{
  int d;

  for (d = 2; d*d <= n; d++) {
    if (!(n % d))
      return 0;
  }

  return 1;
}

int main()
{
    int count, index;
    for (index=2, count=0;count<25;index++){
        if (is_prime(index)){
            printf("%d: %d\n",count, index);
            count++;
        }
    }
  return 0;
}