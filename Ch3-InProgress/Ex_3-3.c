#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 1000
#define NONE -1

enum ctype { LOWER = 1, UPPER, DIGIT };

int getline(char s[], int lim); /* returns length of the input */
bool isvalid(char s[], int len);
void expand(char s1[], char s2[]);

int main(void)
{
    int c;
    char s1[MAX];
    char s2[MAX];

    int len = getline(s1, MAX);

    isvalid(s1, len) ? expand(s1, s2) : printf("\nInvalid input.\n");
}

int getline(char s[], int lim) {
    int c;
    int i;

    for (i = 0; (c = getchar()) != EOF && i < lim && c != '\n'; i++) 
	s[i] = c;

    return i + 1;
}

bool isvalid(char s[], int len) {
    for (int i = 0; i < len; i++) {
	int c = s[i];
	int lastc;
	int ctype;

	if (i == 0 && c == '-') 
	    continue;

	if (c != '-' || !islower(c) || !isupper(c) || !isdigit(c))
	    return false;

	if (lastc == '-' && c == '-')
	    return false;

	if (lastc == '-' && i > 1) { 
	    if (ctype == LOWER && !islower(c))
		return false;
	    if (ctype == UPPER && !isupper(c))
		return false;
	    if (ctype == DIGIT && !isdigit(c))
		return false;
	}

	if (c != '-') {
	    if (islower(c))
		ctype = LOWER;
	    else if (isupper(c))
		ctype = UPPER;
	    else if (isdigit(c))
		ctype = DIGIT;
	}

	lastc = c;
    }

    return true;
}

void expand(char s1[], char s2[]) {

    int s = 0; /* the index of s2 */

    for (int i = 0; s1[i]; i++) {
	int c = s1[i];
	char start = NONE;
	char finish = NONE;

	if (c == '-' && i == 0) {
	    s2[s] = '-';
	    continue;
	}

	if (c == '-' && !s1[i + 1])
	    s2[s] = '-';

	if (c == '-')
	    continue;

	if (finish != NONE) {

	    for (int j = start; j <= finish; j++, s++) {
		s2[s] = j;
	    }

	    /* handle switching from one section like a-z to another like 0-9. or even from a-b to b-c (a-b-c) */
	    char nextchar = s1[i + 1];
	    if (nextchar == '-') {
		start = finish;
		finish = NONE;
	    } else {
		start = NONE;
		finish = NONE;
	    }

	} else {
	    if (start == NONE) 
		start = c;
	    else
		finish = c;
	}

    }
}
