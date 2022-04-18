#include <stdio.h>
void bar(char *data);
int main()
{
        char foo[]={'a','b','c'};
        bar(foo);
        printf("%c\n",*foo);
        return(0);
}
void bar(char *data)
{
        *data='Z';
}
