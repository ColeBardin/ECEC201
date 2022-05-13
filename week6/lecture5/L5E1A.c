#include <stdio.h>
int main()
{
	char foo[]={'H','e','l','l','o','\0','W','o','r','l','d','\0'};
	printf("%s",foo);
	printf("\n%lu",sizeof(foo));
}
