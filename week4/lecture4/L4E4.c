#include <stdio.h>
void value_changer(int val)
{
        val=100;
}
int main()
{
        int foo;
        foo=7;
        value_changer(foo);
        printf("foo: %d\n",foo);
        return(0);
}
