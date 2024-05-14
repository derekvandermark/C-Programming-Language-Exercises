#include <stdio.h>

/* At the time of the writing of K&R the C99 'Standard Integer Types'
 * were not yet created. Therefore I wrote the function assuming a 32
 * bit integer. This works for my machine. */

#define INTLENGTH 32

unsigned rightrot(unsigned x, int n);

int main()
{
    int res1 = rightrot(183, 28); /* should be 2928 */
    int res2 = rightrot(647168, 12); /* should be 158 */
    int res3 = rightrot(15728640, 24); /* should be 4,026,531,840 */

    printf("%u\n%u\n%u\n", res1, res2, res3);
}

unsigned rightrot(unsigned x, int n) 
{
    int i;

    for (i = 0; i < n; i++) {	
	if ((x % 2) > 0) {                    /* if x is odd, the rightmost bit is 1 */
	    x = x >> 1;
	    x = x | (1 << (INTLENGTH - 1));   /* sets leftmost bit to 1 */
	} else {                              /* if x is even, the rightmost bit is 0 */
	    x = x >> 1;
	}
    }

    return x;
}
