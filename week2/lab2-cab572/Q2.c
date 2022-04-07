#include <stdio.h>

int is_prime(int n)
{
    int d;
    /* iterate d from 2 to n^0.5 */
    for (d = 2; d*d <= n; d++) {
        /* if d divides n with a remainder of 0 */
        if (!(n % d))
            /* n is not prime */
            return 0;
    }
    /* if there are no numbers between 2 and n^0.5 that divide n with no remainder, n is prime */
    return 1;
}

int main()
{
    int count, index;
    /* increment index and check primeness until count=25 */
    for (index=2, count=0;count<25;index++){
        /* check primeness of index */
        if (is_prime(index)){
            /* increment count and print the number */
            printf("%d: %d\n",++count, index);
        }
    }
    return 0;
}