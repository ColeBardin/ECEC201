/* Homework 6: Question 1
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q1 Q1.c
   Then run your compiled program with: ./Q1
*/
#include <stdio.h>
#include <stdlib.h>

/* Your code goes here */
char *duplicate(const char *src){
	int i;
	char *dst;

	/* Get length of src string manually if string.h shouldn't be included. else just use strlen() */
	for(i=0;src[i]!='\0';i++);
	/* malloc length of src struing plus 1 for null char */
	dst = malloc(i+1);
	/* Return NULL if Malloc fails */
	if (!dst) 
		return NULL;
	/* Reset i to be 0 */
	i = 0;
	/* Copy src string into memory allocated for dst string */
	while ((dst[i] = src[i]) != '\0'){
		i++;
	}
	/* Return heap address for dst string */
	return dst;
}

int main()
{
	char *dst;

	char *test = "Simplicity is the ultimate sophistication.";

	dst = duplicate(test);
	
 	printf("%s", dst);

	free(dst);

	return 0;
}
