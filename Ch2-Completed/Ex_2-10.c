#include <stdio.h>

/* The difference between the uppercase char value and lowercase char value in ASCII */
#define ASCIIDIFF 32

/* The values of 'A' and 'Z' in ASCII */
#define A 65
#define Z 90

#define MAX 1000

void lower(char str[]);

int main()
{
    int c, i;
    char string[MAX];

    for (i = 0; (c = getchar()) != EOF; i++) {
	string[i] = c;
    }

    lower(string);

    printf("\nTo Lower: %s\n", string);
}

void lower(char str[])
{
    int i = 0;

    while (str[i]) {
	str[i] = (str[i] >= A && str[i] <= Z) ? str[i] + ASCIIDIFF : str[i];
	i++;
    }
}
