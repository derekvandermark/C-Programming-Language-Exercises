#include <stdio.h>

/* In a two's complement number system, x&=(x-1) deletes the rightmost 1-bit in x. Explain why.
 *
 * Answer:
 *
 * Subtracting 1 from any number 'x' will delete the current rightmost 1-bit. If the rightmost bit was a 1,
 * it simply becomes a 0. If any other bit was the rightmost 1-bit, it would become a 0, and every bit 
 * to the right of it would become a 1, which would add up to 1 less than the value of the deleted 1 bit.
 * The &= assignment operator is merely assigning to 'x' the value of the expression x & (x - 1). The &
 * operator will only keep 1-bits in 'x' as a 1-bit if the same bit in (x - 1) is also a 1. Due to the reasoning
 * explained before, the rightmost 1-bit of 'x' will be a 0 in the value (x - 1). It will therefore become a 0
 * in 'x'. All 0-bits in 'x' will remain 0-bits.
 * 
*/

int bitcount(unsigned x);

int main()
{
    int res1 = bitcount(128); /* should be 1 */
    int res2 = bitcount(127); /* should be 7 */
    int res3 = bitcount(35);  /* should be 3 */

    printf("%d\n%d\n%d\n", res1, res2, res3);
}

int bitcount(unsigned x)
{
    int b = 0;

    while (x > 0) {
	x &= (x - 1);
	b++;
    }

    return b;
}
