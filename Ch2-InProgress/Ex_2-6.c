#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    int res1 = setbits(93, 4, 3, 198); /* should be 89 */
    int res2 = setbits(142, 7, 4, 53); /* should be 94 */
    int res3 = setbits(19, 2, 2, 40);  /* should be 17 */

    printf("%d\n", res1);
    printf("%d\n", res2);
    printf("%d\n", res3);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    int rightmost_n = ~(~0 << n);   /* rightmost n bits set to 1 */
    int nofy = y & rightmost_n;
    int nofy_at_p = nofy << (p - n + 1);
    int left_of_p = ~0 << (p + 1);
    int right_of_p = ~(~0 << (p - n + 1));
    int not_p = left_of_p ^ right_of_p; /* all bits 1 except from p to p - n */
    int just_p = ~not_p;  /* all bits 0 except from p to p - n */
    nofy_at_p = nofy_at_p ^ not_p;
    x = x | just_p;   /* original x except all 1s from p to p - n */

    return x & nofy_at_p; 
}
