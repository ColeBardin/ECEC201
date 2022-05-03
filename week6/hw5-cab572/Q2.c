/* Homework 5: Question 2
	 Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q2 Q2.c
	 Then run your compiled program with: ./Q2
*/

#include <stdio.h>


struct fraction {
	int numerator;
	int denominator;
};


void reduce(struct fraction *f)
{
	/* Get prior numerator and denominator from struct */
	int a = f->numerator;
	int b = f->denominator;
	/* Apply Euclid's method to get GCD */
	while( b != 0){
		a += b;
		b = a - b;
		a -= b;
		b = b%a;
	}
	/* Reduce each member by the GCD */
	f->numerator /= a;
	f->denominator /= a;
}


void add(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
	/* Do fraction addition and store in the result struct */
	result->numerator = f2->denominator*f1->numerator + f1->denominator*f2->numerator;
	result->denominator = f1->denominator*f2->denominator;
	/* Reduce the result fraction */
	reduce(result);
}


void subtract(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
	/* Do fraction subtraction and store in the result struct */
	result->numerator = f2->denominator*f1->numerator - f1->denominator*f2->numerator;
	result->denominator = f1->denominator*f2->denominator;
	/* Reduce the result fraction */
	reduce(result);
}


void multiply(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
	/* Do fraction multiplication and store in result struct */
	result->numerator = f1->numerator*f2->numerator;
	result->denominator = f1->denominator*f2->denominator;
	/* Reduce the result fraction */
	reduce(result);
}


void divide(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
	/* Perform fraction division and store in result struct */
	result->numerator = f1->numerator*f2->denominator;
	result->denominator = f1->denominator*f2->numerator;
	/* Reduce the result struct */
	reduce(result);
}


int main()
{
	struct fraction result; 
	
	struct fraction f1 = {20, 15}; 
	struct fraction f2 = {22, 12}; 
	struct fraction f3 = { 4, 12}; 

	reduce(&f1);
	printf("Reduce f1: %d/%d\n", f1.numerator, f1.denominator);

	add(&result, &f2, &f3);
	printf("  f2 + f3: %d/%d\n", result.numerator, result.denominator);

	subtract(&result, &f2, &f3);
	printf("  f2 - f3: %d/%d\n", result.numerator, result.denominator);

	multiply(&result, &f2, &f3);
	printf("  f2 * f3: %d/%d\n", result.numerator, result.denominator);

	divide(&result, &f2, &f3);
	printf("  f2 / f3: %d/%d\n", result.numerator, result.denominator);

	return 0;
}
