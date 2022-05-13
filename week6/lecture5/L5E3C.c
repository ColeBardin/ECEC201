#include <stdio.h>
char *get_fun()
{
	static char fun[]="Fun!";
	return fun;
}

int main()
{
	char  *foo=get_fun();
	foo[0]='B';
	printf("\n%s", foo);
	return(0);
}
