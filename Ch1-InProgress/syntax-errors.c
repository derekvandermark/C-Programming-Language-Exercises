#include <stdio.h>
#include <math.h>

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
int adderror(char errors[], int index, char newerror[]);
void formaterror(char error[], int line);
char singledigitinttochar(int num);
void inttostr(int num, char str[]);

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

	if (c == '\n') {
	    ++fileline;
	    continue;
	}

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
		char newerror[] = "Mismatching closing bracket. Line: ";
		formaterror(newerror, fileline);
		erroridx += adderror(errors, erroridx, newerror);
	    }
	}
    }


    printf("\n\n%s\n\n", errors);
}

char singledigitinttochar(int num) {
    switch (num) {
	case 9: return '9';
		break;
	case 8: return '8';
		break;
	case 7: return '7';
		break;
	case 6: return '6';
		break;
	case 5: return '5';
		break;
	case 4: return '4';
		break;
	case 3: return '3';
		break;
	case 2: return '2';
		break;
	case 1: return '1';
		break;
	default: return '0';
    }
}

void inttostr(int num, char str[]) {
    int greaternum; /* a number greater than num, overnum = 10^x */
    int x;
    int index;
    greaternum = 0;
    x = 0;
    index = 0;

    while (num >= pow(10, x)) {
	++x;
    }

    greaternum = pow(10, x);

    while (x >= 1) {
	int decrement, decrementee;
	decrementee = pow(10, x);
	decrement = pow(10, x - 1);

	while (num < decrementee) {
	    decrementee -= decrement;
	}

	str[index] = singledigitinttochar(decrementee / decrement);
	++index;
	--x;
    }
}

void formaterror(char error[], int line) {
    int i, j;
    i = 0;
    j = 0;

    while (error[i]) {
	if (!error[i + 1]) {
	    char linestr[MAX];
	    inttostr(line, linestr);
	    while (linestr[j]) {
		error[i + j + 1] = linestr[j];
		++j;
	    }
	}

	++i;
    }

    error[i + j + 1] = '\n';
}

int adderror(char errors[], int index, char newerror[]) {
    int i;
    i = 0;

    while (newerror[i]) {
	errors[index + i] = newerror[i];  /* due to i's final increment it will be out of index in newerror[], making errors[] index 1 ahead of the actual */
	++i;
    }

    return i; /* increment the index of the error array by the chars in newerror (this returned value) */
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
