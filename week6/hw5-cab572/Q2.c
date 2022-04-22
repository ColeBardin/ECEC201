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
  /* Your code goes here */
}


void add(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
  /* Your code goes here */
}


void subtract(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
  /* Your code goes here */
}


void multiply(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
  /* Your code goes here */
}


void divide(struct fraction *result, const struct fraction *f1, const struct fraction *f2)
{
  /* Your code goes here */
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