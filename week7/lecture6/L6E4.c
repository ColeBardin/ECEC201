#include <stdlib.h>
#include <stdio.h>

        struct stuff {
                int val;
                char key;
                float pi;
        };

        int main()
        {
                struct stuff *foo;
                foo=malloc(sizeof(*foo));
                foo->val=1;
                foo->key='B';
                foo->pi=3.14f;

                printf("val: %d\n",foo->val);
                printf("key: %c\n",foo->key);
                printf("pi: %.2f\n",foo->pi);
                free(foo);
                return(0);
        }
