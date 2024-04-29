#include <stdio.h>

#define INCOMMENT 1
#define OUTCOMMENT 0
#define IN2QUOTE 2
#define IN1QUOTE 1
#define OUTQUOTE 0
#define OPENBRACK 1
#define REGCHAR 0
#define CLOSEBRACK -1
#define SQUOTE 2
#define DQUOTE 3
#define MAX 1000
#define ASCIICOUNT 128

void asciipair(char charpairs[]);
int chartype(int c);
void adderror(char errors[], int index, char newerror[]);

int main()
{
    int c, prevchar, qstate, cstate, type, openidx, erroridx, fileline;
    char errors[MAX];
    char openchars[MAX];    /* an array of opening characters that have yet to be closed */
    char charpairs[ASCIICOUNT];

    /* set initial values */
    openidx = -1;
    erroridx = 0;
    fileline = 1;
    qstate = OUTQUOTE;
    cstate = OUTCOMMENT;

    asciipair(charpairs);   /* make array for matching brackets/quotes */

    while ((c = getchar()) != EOF) {
	type = chartype(c);

	if (type == REGCHAR)
	    continue;

	if (type == OPENBRACK) {
	    ++openidx;
	    openchars[openidx] = c;
	}

	if (type == CLOSEBRACK) {
	    if (openchars[openidx] == charpairs[c]) {
		--openidx;  /* so that next openchar replaces the current last one, or next close char is compared to new last one */
	    } else {
		adderror(errors, erroridx, "Mismatching closing bracket.\n");
	    }
	}
    }


    printf("\n\n%s\n\n", errors);
}

void adderror(char errors[], int index, char newerror[]) {
    int i;

    i = 0;

    while (newerror[i]) {
	errors[index + i] = newerror[i];  /* due to i's final increment it will be out of index in newerror[], making errors[] index 1 ahead of the actual */
	++i;
    }

    index += i; /* increment the index of the error array by the chars in newerror */
}

void asciipair(char charpairs[]) 
{
    int i;
    
    for (i = 0; i < ASCIICOUNT; ++i) {
        switch (i) {
	    case 34: charpairs[i] = 34;   /* " returns " */
		     break;
	    case 39: charpairs[i] = 39;   /* ' returns ' */
		     break;
	    case 41: charpairs[i] = 40;   /* ) returns ( */
		     break;
	    case 93: charpairs[i] = 91;   /* ] returns [ */
		     break;
	    case 125: charpairs[i] = 123; /* } returns { */
		     break;
	    default: charpairs[i] = 48;   /* 0  character */
        }
    }
}

int chartype(int c)
{
    int i;
    char open[3];
    char close[3];

    open[0] = '(';
    open[1] = '[';
    open[2] = '{';
    
    close[0] = ')';
    close[1] = ']';
    close[2] = '}';

    for (i = 0; i < 3; ++i) {
	if (c == open[i])
	    return OPENBRACK;
	else if (c == close[i])
	    return CLOSEBRACK;
	else if (c == '"')
	    return DQUOTE;
	else if (c == '\'')
	    return SQUOTE;
    }
    
    return REGCHAR;
}
