#include <stdio.h>

void print_sum(int a,int b,int limit)
{
    int sum = a+b;
    if(sum>limit)
            return;
    printf("a+b: %d\n",sum);
    return;
}

int main()
{
    print_sum(6,9,20);
    return(0);
}
