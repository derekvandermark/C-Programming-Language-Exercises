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
    printf("\nMake escapes visible: \n%s\n", s);

    unescape(s, t);
    printf("\nMake escapes real characters again: \n%s\n", t); 
}

void escape(char s[], char t[])
{
    int ti = 0;
    int si = 0;

    while (t[ti]) {
	switch (t[ti]) {
	    case '\t':
		s[si++] = '\\';
		s[si] = 't';
		break;
	    case '\n':
		s[si++] = '\\';
		s[si] = 'n';
		break;
	    default:
		s[si] = t[ti];
		break;
	}

	ti++;
	si++;
    }
}

void unescape(char s[], char t[])
{
    int ti = 0;
    int si = 0;
    int lastc;

    while (s[si]) {
	switch (s[si]) {
	    case 't':
		if (lastc == '\\')
		    t[--ti] = '\t';
		break;
	    case 'n':
		if (lastc == '\\')
		    t[--ti] = '\n';
		break;
	    default:
		t[ti] = s[si];
		break;
	}

	lastc = s[si];

	ti++;
	si++;
    }
}
