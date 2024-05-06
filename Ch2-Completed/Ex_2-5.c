#include <stdio.h>

#define ASCII 128

int any(char s1[], char s2[]);

int main() 
{
    char str1[] = "Where is the first letter from str2?"; /* output should be 13, the index of 'f' in 'first' */
    char str2[] = "abcdf!";

    printf("%d", any(str1, str2));
}

int any(char s1[], char s2[])
{
    int cs[ASCII];
    int i, j;

    for (i = 0; s2[i] != '\0'; i++) 
	cs[s2[i]] = 1;

    for (j = 0; s1[j] != '\0'; j++) {
	if (cs[s1[j]] == 1)
	    return j;
    }

    return -1;
}
