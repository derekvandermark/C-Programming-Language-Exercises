#include <stdio.h>
#include <ctype.h>
#include <math.h>


double atof(char s[], int startindex)
{
    double val, power, result;
    int i, sign;

    for (i = startindex; isspace(s[i]); i++)  /* skip spaces */
	;

    sign = s[i] == '-' ? -1 : 1;

    if (s[i] == '-' || s[i] == '+')
	i++;

    for (val = 0.0; isdigit(s[i]); i++) 
	val = (10.0 * val) + (s[i] - '0');
    

    if (s[i] == '.')
	i++;

    for (power = 1.0; isdigit(s[i]); i++) {
	val = (10.0 * val) + (s[i] - '0');
	power *= 10.0;
    }

    result = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E')
	return result * pow(10, atof(s, ++i));
    else
	return result;
}
