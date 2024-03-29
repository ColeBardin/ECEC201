/* Homework 6: Question 2
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q2 Q2.c
   Then run your compiled program with: ./Q2
*/
#include <stdio.h>

#define ELEMENTS 8

#include <stdlib.h>
/* Your code goes here */
int *create_array(int n, int inital_value){
	int *arr;
	/* Error handle malloc of n ints */
	if (NULL == (arr = malloc(n*sizeof(*arr)))){
		/* Retur arr (NULL PTR) */
		return arr;
	}
	/* Set each value in array to initial_value, starting from the last value at index n-1 */
	for(;n>0;arr[--n]=inital_value);
	return arr;
}

int main()
{
  int i;
  int *foo;

  foo = create_array(ELEMENTS, 79);

  if (foo)
    for (i=0; i<ELEMENTS; i++)    
      printf("%d: %d\n", i, foo[i]);

  free(foo);

  return 0;
}
