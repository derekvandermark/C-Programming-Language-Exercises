#include <stdio.h>

#define MAX 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    int c, i;
    char t[MAX], s[MAX];

    i = 0;

    while ((c = getchar()) != EOF) {
	t[i] = c;
	i++;
    }

    escape(s, t);
    printf("Make escapes visible: \n%s\n", s);

    unescape(s, t);
    printf("Make escapes real characters again: \n%s\n", s);
}

void escape(char s[], char t[])
{
    int ti = 0;
    int si = 0;

    while (t[i]) {
	switch (t[i]) {
	    case '\t':
		break;
	    case '\n':
		break;
	    default:
		break;
	}

	ti++;
	si++;
    }
}
