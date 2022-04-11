#include <stdio.h>
void foo(void)
{
char c='a';
c=c-32;
printf("c: %c (%d)\n",c,c);
return;
}

int main()
{
foo();
}
