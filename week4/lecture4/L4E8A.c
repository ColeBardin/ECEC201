#include <stdio.h>

int main()
{
	int i;
	short foo[]={1,2,3};
	printf("foo:  %zu",sizeof(foo));
	printf("  bytes\n");
	for(i=0;i<3;i++)
		printf("%d ",*(foo+i));
	return(0);
}
