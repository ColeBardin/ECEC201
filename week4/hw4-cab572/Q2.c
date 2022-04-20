/* Homework 3: Question 2
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q2 Q2.c
   Then run your compiled program with: ./Q2
*/

#include <stdio.h>

int *find_largest (int *a, int n)
{
	int max = a[0]; /* Create var to hold max, init to first element */
	int index; /* Create index variable */
	/* Iterate through each element of the array */
	for (index=0;index<n;index++){
		/* If the current element is bigger than the previous max */
		if (a[index] > max){
			/* Set max to the current value */
			max = a[index];
		}
	}
	/* Use main stack frame address to store max value */
	*a = max;
	/* Return address of max value */
	return a;
}


int main ()
{
  int *largest;
  
  int numbers[] = {10,  1, 54,  8, 78, 13,  4,
                   32, 72, 13, 43, 66, 42, 21,
                   41, 87, 23, 11, 52,  7,  2,
                    3, 33,  5,  9, 67, 12, 17};

  int n = sizeof(numbers)/sizeof(int);
  
  largest = find_largest(numbers, n);
  
  printf("Of the %d numbers passed,\n", n);
  printf("%d was the largest\n", *largest);
  
  return 0;
}
