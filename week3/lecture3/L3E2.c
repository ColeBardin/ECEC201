#include <stdio.h>
int main()
{
	int i;
	char foo=2;
	float my_float;
	unsigned long int size_of_float;

	printf("%lu bytes\n",sizeof(int));
	printf("%lu bytes \n",sizeof(char));
	printf("%lu bytes\n",sizeof(float));

	printf("%lu bytes\n",sizeof(i));
	printf("%lu bytes\n",sizeof(foo));
	printf("%lu bytes\n",sizeof(my_float));

	printf("%lu bytes\n",sizeof(foo*3.14f));

	return(0);
}
