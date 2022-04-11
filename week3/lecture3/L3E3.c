#include <stdio.h>

void foo()
{
    char n='a';
    int m=9001;
    printf("n: %c (%d)\n",n,n);
    printf("m: %d\n",m);
    return;
}

int main()
{
    foo();
}
