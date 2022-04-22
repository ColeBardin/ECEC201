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
	for (;i<=j;i++){
		total += g(i);
		if (i==j)
			total += g(i);
	}
	return total;
}


int main()
{
  printf("Result: %d\n", sum(g, 4, 3));

  return 0;
}
