#include <stdio.h>

int strindex(char s[], char t[]);

int main()
{
    char str1[] = "Hello can I have a cup of coffee? Or do you not sell coffee here? I was told there was coffee...";
    char str2[] = "Hello can I have a cup of coffee? Or do you not sell coffee here?";
    char str3[] = "Hello can I have a cup of coffee?";
    char pattern[] = "coffee";

    printf("Index: %d\n", strindex(str1, pattern));
    printf("Index: %d\n", strindex(str2, pattern));
    printf("Index: %d\n", strindex(str3, pattern));
}

int strindex(char s[], char t[]) 
{
    int i, j, k;

    /* get length of s */
    for (i = 0; s[i] != '\0'; i++)
	;

    for (i = i; i >= 0; i--) {
	for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; j++, k++) 
	    ;

	if (k > 0 && t[k] == '\0')
	    return i;
    }

    return -1;
}
