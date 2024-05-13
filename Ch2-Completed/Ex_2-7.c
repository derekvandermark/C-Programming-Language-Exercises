#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    int res1 = invert(157, 6, 3); /* should be 237 */
    int res2 = invert(103, 2, 2); /* should be 97 */
    int res3 = invert(96, 4, 4);  /* should be 126 */   

    printf("%d\n%d\n%d\n", res1, res2, res3);
}

unsigned invert(unsigned x, int p, int n)
{
    int left_ones = ~0 << (p + 1);              /* bits set to 1 left of p */
    int right_ones = ~(~0 << (p + 1 - n));      /* bits set to 1 right of p + n */
    int ones_around_p = left_ones | right_ones; /* bits set to 1 left of p and right of p + n */
    int zeros_around_p = ~ones_around_p;        /* inverted */
    return x ^ zeros_around_p; 
}
