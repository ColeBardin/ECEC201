/* Homework 3: Question 3
	 Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q3 Q3.c
	 Then run your compiled program with: ./Q3
*/

#include <stdio.h>

void zero_array (int *a, int n)
{
	/* Only modify this function */
	int *q; /* Make pointer variable */
	/* Make q point to first element of a
	Decrease n each time, repeat while n>0 => repeat n times, n goes from n to 0
	After each iteration, point q at nth element (Element 0 + n)
	As n decreases, this will iterate through each element of the array
	*/
	for (q=&a[0] ; n>0 ; n--, q=&a[0]+n)
		/* Set whatever q is pointing to to 0 */
		*q = 0;
}


void print_contents (int *a, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
	  printf("%2d ", a[i]);
	  
	  if (!((i+1) % 7))
	    printf("\n");
	}
}


int main ()
{
	int numbers[] = {10,  1, 54,  8, 78, 13,  4,
	                 32, 72, 13, 43, 66, 42, 21,
	                 41, 87, 23, 11, 52,  7,  2,
	                  3, 33,  5,  9, 67, 12, 17};
	
	int n = sizeof(numbers)/sizeof(int);
	
	printf("Contents of numbers[] BEFORE:\n");
	print_contents(numbers, n);
	
	zero_array(numbers, n);
	
	printf("\nContents of numbers[] AFTER:\n");
	print_contents(numbers, n);
	  
	return 0;
}
