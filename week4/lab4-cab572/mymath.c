void compute_fibs (unsigned long int *fibs, unsigned int *N){
	/* create current_fib, next_fib vars as unsigned long ints */
	unsigned long int current_fib = 0;
	unsigned long int next_fib = 1;
	/* Make unsigned int for index variable */
	unsigned int index;

	/* Iterate N times */
	for (index=0; index<*N; index++){
		/* Store current fib in current index of fibs array */
		fibs[index] = current_fib;
		
		/* Set next fib to itself plus next */
		next_fib += current_fib; 
		/* Set current fib to be next fib minus current fib (last next fib) */
		current_fib = next_fib - current_fib;
	}
}

