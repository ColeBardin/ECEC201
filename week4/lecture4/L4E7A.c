#include <stdio.h>

void bar(char *data);

int main()
{
	int i;
	char foo[]={'a','b','c'};
	for(i=0;i<=2;i++)
	{
		bar(foo+i);
		printf("%c,%c,%c\n",*foo,*(foo+1),*(foo+2));
	}
	return(0);
}

void bar(char *data)
{
	*data='Z';
}
