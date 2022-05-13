#include <stdio.h>
char *get_fun()
{
	static char fun[]="Fun!";
	return fun;
}

int main()
{
	printf("\n%s", get_fun());
	return(0);
}
