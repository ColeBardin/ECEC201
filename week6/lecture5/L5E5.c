#include <stdio.h>
        char *my_strcpy(char *dst, const char *src)

        {
                char *p=dst;
                while((*dst++=*src++)!='\0');
                return p;
        }

        int main()
        {
                char a[7]="DREXEL";
                char b[7];
                my_strcpy(b,a);
                printf("\n%s",b);
                //printf("%c",b[1]);
                return(0);
        }
