#include <stdio.h>
#include <limits.h>

#define MAX 100

void itoa(int n, char s[], int w);

int main()
{
    char s[MAX];
    itoa(1567, s, 5);
    itoa(-299144, s, 3);
    itoa(-342342, s, 17);
    itoa(15, s, 1);
}

void itoa(int n, char s[], int w)
{
    int i = 0;
    int sign;
    int digit;
    int lowestn = (n == INT_MIN);

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

    while (i < w) {
	s[i++] = ' ';
    }

    s[i] = '\0';
    /* reverse(s) goes here */
    printf("\n%s\n", s);
}
