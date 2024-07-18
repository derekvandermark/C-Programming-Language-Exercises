#include <stdio.h>

/* DISCLAIMER: This is not my own solution, but one provided by the official answer book. */

void expand(char s1[], char s2[]);

int main() 
{
    char result[256];

    expand("a-z", result);
    printf("\na-z\n%s\n", result);

    expand("!-~", result);
    printf("\n!-~\n%s\n", result);

    expand("-0-9hellothereg-l-o-", result);
    printf("\n-0-9hellothereg-l-o-\n%s\n", result);
}

void expand(char s1[], char s2[])
{
    char c;
    int i, j;

    i = j = 0;

    while ((c = s1[i++]) != '\0') { /* fetch a char from s1[] */
	if (s1[i] == '-' && s1[i + 1] >= c) {
	    i++;
	    while (c < s1[i])       /* expand shorthand */
		s2[j++] = c++;
	} else
	    s2[j++] = c;            /* copy the character */
    }
    s2[j] = '\0';
}


