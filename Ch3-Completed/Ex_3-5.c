#include <stdio.h>
#include <limits.h>

void itob(int n, char s[], int b);

int main()
{
    char s[100];
    itob(307, s, 16);
    itob(165, s, 16);
    itob(32549, s, 8);
    itob(-2147483648, s, 10);
    itob(-2147483648, s, 16);
    itob(-2147483648, s, 2);
}

void itob(int n, char s[], int b)
{
    int i = 0;
    int sign;
    int digit;
    int overflow = 0;
    int lowestn = (n == INT_MIN);

    if ((sign = n) < 0 && lowestn)
	n = INT_MAX;
    else if ((sign = n) < 0)
	n = -n;

    do {
	if (overflow) {
	    n += 1;    /* add back the value lost in overflow */
	    overflow = 0;
	}

	if (n % b > 9)                       /* notation for digits greater than 9 starts with 'A' and ends with 'Z' */
	    digit = 'A' + ((n % b) % 10);    /* digit is only the remainder modulo 10 greater than 'A', since 'A' represents 10 */
	else 
	    digit = '0' + n % b;
		

	if (i == 0 && lowestn) {
	    if ((n % b + 1) / b == 1) {      /* if the increment overflows the digit */
	        digit = '0';
		n -= n % b;
		overflow = 1;                /* just a truthy value */
	    } else
		digit += 1;
	}

	s[i++] = digit;
    } while ((n /= b) > 0);

    if (sign < 0)
	s[i++] = '-';

    s[i] = '\0';
    /* reverse(s) here */
    printf("%s\n", s);
}
