#include <stdio.h>
int is_small(int i)
{
	if(i<5)
		return(1);
	else
		return(0);

}

float square(int i)
{
	float num=i;
	return num*num;
}

int main()
{
	int i;
	for(i=0;is_small(i);i++)
		printf("%d^2=%f\n",i,square(i));
	return(0);
}
