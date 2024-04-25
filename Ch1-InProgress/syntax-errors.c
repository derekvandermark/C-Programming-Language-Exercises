#include <stdio.h>

#define INQUOTE 1
#define OUTQUOTE 0
#define MAX 1000
#define ASCIICOUNT 128

/* return char array with ASCII index of closing chars being the opening char value */

void asciipair(char charpairs[]);

int main()
{
    int c, fileidx, openidx, errorsidx, fileline;
    char errors[MAX];
    char openchars[MAX];    /* an array of opening characters that have yet to be closed */
    char charpairs[ASCIICOUNT];

    asciipair(charpairs);   /* make array for matching brackets/quotes */

    while ((c = getchar()) != EOF) {

    }


    printf("\n\n%s\n\n", allerrors);
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



