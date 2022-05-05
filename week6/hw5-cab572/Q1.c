/* Homework 5: Question 1
   Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q1 Q1.c
   Then run your compiled program with: ./Q1
*/

#include <stdio.h>


int g(int val)
{
  return val * val;
}


/* Your sum function goes here */
int sum(int (*g)(int i), int i, int j) {
	int total = 0;
	/* If i and j are equal, total is g(i) + g(j) */
	if (i==j){
		total += g(i);
	}
	/* Repeat while i is less than j */
	while (i<=j){
		/* Add g(i) to the total and increment i */
		total += g(i);
		i++;
	}
	return total;
}

int main()
{
  printf("Result: %d\n", sum(g, 10, 20));

  return 0;
}

