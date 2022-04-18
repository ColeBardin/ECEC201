#include <stdio.h>
        int foo;
void value_changer()
{
        foo=100;
}
int main()
{
        foo=37;
        value_changer(foo);
        printf("foo: %d\n",foo);
        return(0);
}
