#include <stdio.h>

int main()
{
    int a = 5;
    int b = 9;

    printf("Bitwise AND test: %d\n", a & b);

    int c = 8;
    int d = 15;

    printf("Bitwise inclusive OR test: %d\n", c | d);

    int e = 19;
    int f = 7;

    printf("Bitwise exclusive OR test: %d\n", e ^ f);

    int g = 8;
    int h = 3;

    printf("Bitwise left shift test: %d\n", g << h);

    int i = -5;
    int j = 2;

    printf("Bitwise right shift test: %d\n", i >> j);

    int k = 10;

    printf("Bitwise unary test: %d\n", ~k);

}
