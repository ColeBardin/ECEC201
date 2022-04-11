#include <stdio.h>
int main()
{
        int i;
        printf("Squares of evens only:\n");
                for(i=0;i<20;i++)
                        {
                                printf("%d: ",i);
                                if(i%2)
                                        {
                                                printf("Skipping...\n");
                                                continue;
                                        }
                                        printf("%d\n",i*i);
                        }
        return(0);
}
