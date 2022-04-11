#include <stdio.h>

int poly(int x)
{
	int value;
	value=(((((3*x+2)*x-5)*x-1)*x+7)*x-6);
	return(value);
}

int main()
{
	int x,value;
	printf("Enter x:");
	scanf("%d",&x);
	value=poly(x);
	printf("Value of polynomial is = %d\n",value);
	return(0);
}
