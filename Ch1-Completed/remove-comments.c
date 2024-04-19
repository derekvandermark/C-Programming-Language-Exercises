#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX 1000 /* THIS comment has '\0' and "string" and '\n' '\n' '\n' */

int main()
{
    int i, c, last, state;
    char nocomment[MAX];

    i = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
	if (state == OUT) {
	    nocomment[i] = c;
	    ++i;
	};

	if (i > 0) {

	    if (state == OUT && nocomment[i - 2] == '/' && c == '*') {
		nocomment[i - 2] = '\0'; /* this will be replaced by any future chars */
		state = IN;
		i-=2;
	    }

	    if (state == IN && last == '*' && c == '/') {
		state = OUT;  
	    }

	    if (state == IN)
		last = c;
	}
    }

    if (nocomment[i - 1] != '\0')
	nocomment[i] = '\0'; /* THIS IS A TEST COMMENT */

    printf("\n\n%s\n\n", nocomment);
}
