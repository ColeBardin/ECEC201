#include <stdlib.h>
#include <stdio.h>
int main()
{
        int i;
        int *foo;
        foo=malloc(12);
        *foo=25;
        *(foo+11)=5400;
        for(i=0;i<12;i++)
        printf("\nfoo: %d",*(foo+i));
        free(foo);
        return(0);
}
