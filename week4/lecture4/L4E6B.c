#include <stdio.h>
int main()
{
        unsigned long int foo[]={34,2,456,1234567890,0,1,87,876,98,1000};
        printf("size_of_foo: %zu",sizeof(foo));
        printf("bytes\n");
        return(0);
}
