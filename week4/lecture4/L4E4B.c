#include <stdio.h>

int value_changer(int val)
{
	val=100;
	return val;
}

int main()
{
	int foo=37;
	foo=value_changer(foo);
	printf("foo: %d\n",foo);
	return(0);
}
