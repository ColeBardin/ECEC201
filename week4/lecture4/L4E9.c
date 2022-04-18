#include <stdio.h>

int main()
{
	short *p;
	short foo[]={1,2,3};
	printf("foo:  %zu",sizeof(foo));
	printf("  bytes\n");
	for(p=foo;p<foo+3;p++)
		printf("%d ",*p);
	return(0);
}
