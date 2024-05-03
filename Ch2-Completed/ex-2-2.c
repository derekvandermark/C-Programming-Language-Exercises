#include <stdio.h>

int main()
{
    int i, c, lim;

    lim = 10;

    for (i = 0; (i < lim - 1) == ((c = getchar()) != '\n') == (c!= EOF); ++i)
	printf("%c", c);

    printf("\n%d", i);
}
