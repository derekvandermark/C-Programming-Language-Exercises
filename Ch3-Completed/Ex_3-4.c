#include <stdio.h>
#include <limits.h>

#define MAX 100

/* 
 * The original version of itoa will not be able to handle the largest negative number in a 2's complement representation
 * because when it is made positive it will overflow the int. The largest negative number's magnitude is 1 greater than that
 * of the largest positive number's magnitude.
 */

void itoa(int n, char s[]);

int main()
{
    char s[MAX];
    itoa(-128, s); 
    itoa(1243253, s);
    itoa(-2147483647, s);
    itoa(-2147483648, s);
    itoa(2147483647, s);
}

void itoa(int n, char s[])
{
    int i = 0;
    int sign;
    int digit;
    int lowestn = (~n == INT_MAX);

    if ((sign = n) < 0 && lowestn) 
	n = INT_MAX;
    else if ((sign = n) < 0)
	n = -n;

    do {
	digit = n % 10 + '0';

	if (i == 0 && lowestn)             
	    digit += 1;

	s[i++] = digit;
    } while ((n /= 10) > 0);

    if (sign < 0)
	s[i++] = '-';

    s[i] = '\0';
    /* reverse(s) goes here */
    printf("\n%s\n", s);
}

