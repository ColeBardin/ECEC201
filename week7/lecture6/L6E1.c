#include <stdio.h>
int main(int argc, char **argv)
{
	int ten=10;
	int *foo;
	int **bar;
	foo=&ten;
	printf("foo:  %p\n",foo);
	printf("*foo: %d\n",*foo);

	bar=&foo;
	printf("  bar: %p\n",bar);
	printf(" *bar: %p\n",*bar);
	printf("**bar: %d\n", **bar);
	return(0);
}
