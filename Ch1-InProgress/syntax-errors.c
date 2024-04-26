#include <stdio.h>

#define INQUOTE 1
#define OUTQUOTE 0
#define OPENBRACK 1
#define REGCHAR 0
#define CLOSEBRACK -1
#define SQUOTE 2
#define DQUOTE 3
#define MAX 1000
#define ASCIICOUNT 128

/* return char array with ASCII index of closing chars being the opening char value */

void asciipair(char charpairs[]);
int chartype(int c);

int main()
{
    int c, qstate, cstate, chartype, openidx, errorsidx, fileline;
    char errors[MAX];
    char openchars[MAX];    /* an array of opening characters that have yet to be closed */
    char charpairs[ASCIICOUNT];

    asciipair(charpairs);   /* make array for matching brackets/quotes */

    while ((c = getchar()) != EOF) {
	chartype = chartype(c);

	if (chartype == OPENBRACK) {

	}

    }


    printf("\n\n%s\n\n", errors);
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
	    return  OPENBRACK;
	else if (c == close[i])
	    return CLOSEBRACK;
	else if (c == '"')
	    return DQUOTE;
	else if (c == ''')
	    return SQUOTE;
    }
    

    return REGCHAR;
}
