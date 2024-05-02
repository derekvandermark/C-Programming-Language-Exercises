#include <stdio.h>
#include <limits.h>
#include <float.h>


/* Part 2: Compute values 
 * Assumed sizes
 * char - 8 bits
 * int - 16 bits
 * short - 16 bits
 * long - 32 bits
*/


int main() 
{
   /* int e = EOF;
    char d = 11111111;

    printf("%d\n", e);
    printf("%c\n", d);
*/


    char c;

    while ((c = getchar()) != EOF) {
	printf("%d", c);
    }


    int a = 0xFF;

    printf("%d", a);

    if (EOF == a)
	printf("Yes");
    else 
	printf("No");

    char z = 5;
    char y = 6;
    printf("%c", z * y);
}



/* Part 1: Print values 

int main() {
    printf("Signed char min: %d\n", CHAR_MIN);
    printf("Signed char max: %d\n", CHAR_MAX);
    printf("Unsigned char min: %d\n", 0);
    printf("Unsigned char max: %d\n", UCHAR_MAX);
    printf("Signed short min: %d\n", SHRT_MIN);

    etc...
}

*/



