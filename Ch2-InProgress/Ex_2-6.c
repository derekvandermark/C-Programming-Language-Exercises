#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    int res = setbits(93, 4, 3, 198);

    printf("%d\n", res);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    int rightmost_n = ~(~0 << n);   /* rightmost n bits set to 1 */
    int nofy = y & rightmost_n;
    int nofy_at_p = nofy << (p - n + 1);
    int left_of_p = ~0 << (p + 1);
    int right_of_p = ~(~0 << (p - n + 1));
    int not_p = left_of_p ^ right_of_p; /* all bits 1 except from p to p - n */
    nofy_at_p = nofy_at_p ^ not_p;
    return x & nofy_at_p; 
}
