#define NELEMENTS 100
#include <stdio.h>
int main()
{
	int i;
	int a[NELEMENTS];

	for(i=0;i<NELEMENTS;i++)
	{
		a[i]=2*i;
		printf("%d\n",a[i]);
	}
	return(0);
}
