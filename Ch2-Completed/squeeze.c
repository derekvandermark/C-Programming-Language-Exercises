#include <stdio.h>

#define ASCII 128

void squeeze(char s1[], char s2[]);

int main()
{
    char str1[] = "This string will have characters removed.";
    char str2[] = "No more common chars.";

    squeeze(str1, str2);

    printf("\n%s\n", str1);
}

void squeeze(char s1[], char s2[])
{
    int cs[ASCII];
    int i, j;

    for (i = 0; s2[i] != '\0'; i++) 
	cs[s2[i]] = 1;

    for (i = j = 0; s1[i] != '\0'; i++) {
/*
	printf("%c ", s1[i]);
	printf("%d\n", cs[s1[i]]);
*/

	if (cs[s1[i]] != 1) {  /* some capital letters that were not in s2 did not have a value of 0, but were billions above or below... hence != -1 */
	    s1[j++] = s1[i];
	}
    }

    s1[j] = '\0';
}
