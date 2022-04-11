#include <stdio.h>
int main()
{
        int n;
        int foo;
        for(foo=100,n=0;n<5;n++,foo/=2)
        {
                if(foo<25)
                        break;
                printf("%i: %i\n",n,foo);
        }
        return(0);
}
