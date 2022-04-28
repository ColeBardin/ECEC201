#include <stdio.h>

#define SCANF_ERR	(-1) /* Program error code for when scanf fails */
#define INVALID_NUM	(-2) /* Program error code for when invalid nums are given for N or R */

/* NCR Prototype */
unsigned long int NCR(unsigned int N, unsigned int R);

int main() {
	/* Initialize variables */
	int N, R;
	unsigned long int result;

	/* Scan N and R from keyboard */
	if (scanf("N= %d, R=%d", &N, &R) != 2) {
		/* Handle if scanf does not successfully work */
		printf("ERROR: Scanf call did not match 2 integers!\n");
		return SCANF_ERR;
	}

	/* Check i) and ii) */
	if ( (N == 0) || (R == 0) || (R>N) ) {
		printf("ERROR: Invalid entries for N or R!\n");
		return INVALID_NUM;
	}
	
	/* Call NCR to get result, explicitely cast N and R to unsigned long ints */	
	result = NCR((unsigned int)N,(unsigned long int)R);
	/* Print results */
	printf("Answer = %lu\n", result);

	return 0;
}

/* NCR Definition */
unsigned long int NCR(unsigned int N, unsigned int R) {
	/* Initialize local variables */
	unsigned long int i, result;
	unsigned long int numer = 1;
	unsigned long int denom = 1;

	/* Iterate i to R */
	for (i=0; i < R; i++) {
		/* Multiply numerator by N-i */
		numer *= (N-i);
		/* Multiply denominator by i+1 */
		denom *= (i+1);
	}
	/* Calculate the resulting quotient */
	result = numer/denom;
	return result;
}

