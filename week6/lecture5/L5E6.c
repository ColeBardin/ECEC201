#include <stdio.h>
char *my_strcpy(char *dst, const char *src);
char *my_strcat(char *dst, const char *src);
int main()
{
        char hello_world[20];
        char hello[]="Hello ";
        char world[]="World ";
        my_strcpy(hello_world,hello);
        my_strcat(hello_world,world);
        printf("\n%s",hello_world);
}

char *my_strcpy(char *dst, const char *src)
{
        char *p=dst;
        while((*dst++=*src++)!='\0');
        return p;
}

char *my_strcat(char *dst, const char *src)
{
        char *p=dst;
        while(*dst!='\0')
        dst++;
        while((*dst++=*src++)!='\0');
        return p;
}
