#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

int htoi(char hex[], int len);
int hex_char_to_dec_int(char c);
int is_hex(char hex[]);

int main()
{
    int c, converted;
    int length = 0;
    char str[MAX];

    while ((c = getchar()) != EOF) {
	if (c != '\0') {
	    str[length] = c;
	    ++length;
	}
    }

    if (is_hex(str)) {
	converted = htoi(str, length);
	printf("\nHexadecimal %s = %d in Decimal.\n", str, converted);
    } else {
	printf("Input must be in hexadecimal form.\n"
		"Digits 0-9 and letters a-f or A-F are permitted.\n"
		"You may add a \'0x\' prefix if you wish.\n");
    }
}

int htoi(char hex[], int len)
{

    int i = 0;
    int val = 0;

    while (hex[i]) {
	int place_value = pow(16, len - i - 1);
	int dec_int = hex_char_to_dec_int(hex[i]);
	val += dec_int * place_value;
	++i;
    }

    return val;
}

int hex_char_to_dec_int(char c) 
{
    if (c >= '0' && c <= '9') {
	return c - '0';
    }

    c = toupper(c);

    switch (c) {
	case 'A': return 10;
		  break;
	case 'B': return 11;
		  break;
	case 'C': return 12;
		  break;
	case 'D': return 13;
		  break;
	case 'E': return 14;
		  break;
	case 'F': return 15;
		  break;
	default: return 0;
    }
}

int is_hex(char hex[])
{
    int i = 0;
    int torf = 1;

    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {  /* check for prefix of 0x or 0X */
	    i += 2;
    }

    while (hex[i]) {
	char val = hex[i];
	if (!((val >= '0' && val <= '9') || (val >= 'a' && val <= 'f') || (val >= 'A' && val <= 'F')))
	    torf = 0;
    }

    return torf;
}
