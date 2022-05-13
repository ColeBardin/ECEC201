#include <stdio.h>
size_t my_strlen(const char *s);
        int main()
        {
                size_t len;
                char hello_world[]="Hello World";
                len = my_strlen(hello_world);
                printf("\n%zu",len);
                return(0);
        }

        size_t my_strlen(const char *s)
        {
                size_t i=0;
                while(*(s+i)!='\0')
                i++;
                return(i);
        }
