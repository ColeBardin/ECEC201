#include <stdio.h>
char *get_fun()
{
	static char fun[5];
	int i=0;
	while((fun[i]="Fun!"[i])!=0)
	i++;
	return fun;
}

int main()
{
	printf("\n%s", get_fun());
	return(0);
}
