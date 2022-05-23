#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a = 'a';
	char b = 'b';
	char a2 = 'a';
	if (a==b)
		printf("a=b");
	if (a==a2)
		printf("a=a2");
	return 0;
}
