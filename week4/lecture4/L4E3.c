#include <stdio.h>

int main()
{
	char foo;
	char *foo_ptr;
	foo=5;
	foo_ptr=0x1234;

	printf("     foo: %d\n",foo);
	printf("foo_ptr: :%p\n",foo_ptr);
	printf("&foo_ptr; %p\n", &foo_ptr);
	printf("*foo_ptr: %d\n", *foo_ptr);
	return(0);
}
