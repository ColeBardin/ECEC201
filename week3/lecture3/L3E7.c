#include <limits.h>
#include <stdio.h>
int main(int argc,char** argv)
{
printf("sizeof(short int): %zu bytes\n",sizeof(short));
printf("SHRT_MIN: %i\n",SHRT_MIN);
printf("SHRT_MAX: %i\n",SHRT_MAX);
printf("USHRT_MAX: %i\n",USHRT_MAX);

printf("sizeof(int): %zu bytes\n",sizeof(int));
printf("INT_MIN: %i\n",INT_MIN);
printf("INT_MAX: %i\n",INT_MAX);
printf("UINT_MAX: %u\n",UINT_MAX);

printf("sizeof(long): %zu bytes\n",sizeof(long));
printf("LONG_MIN: %li\n",LONG_MIN);
printf("LONG_MAX: %li\n",LONG_MAX);
printf("ULONG_MAX: %lu\n",ULONG_MAX);
return(0);
}
