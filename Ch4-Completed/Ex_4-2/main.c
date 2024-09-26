#include <stdio.h>

int main()
{
    double atof(char s[], int index);

    printf("123.45e-6: %.8f\n", atof("123.45e-6", 0));
    printf("546.123e-2: %.8f\n", atof("546.123e-2", 0));
}
