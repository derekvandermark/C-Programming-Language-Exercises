#include <stdio.h>

int main()
{
    double atof(char s[], int index);

    printf("123.45e-6: %.8f\n", atof("123.45e-6", 0));
}
