#include <limits.h>

#include "mymath.h"

void compute_fibs (unsigned long int *fibs, unsigned int *N){
	/* Make unsigned int for index variable */
	unsigned int index;
	
	/* Set first and second elements to create fib sequence */
	fibs[0] = 0;
	fibs[1] = 1;

	/* Iterate from 2 to N */
	for (index=2; index<*N; index++){

		/* If next value will overflow max value for unsigned long */
		if ( fibs[index-1] > ULONG_MAX - fibs[index-2] ) {		
			/* Set N to be current number of fibs printed correctly and return */
			*N = index + 1;
			return;
		}
		
		/* Set next fib element */
		fibs[index] = fibs[index-1] + fibs[index-2];		
	}
}

