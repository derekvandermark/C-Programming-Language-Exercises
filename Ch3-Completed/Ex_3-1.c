#include <stdio.h>
#include <time.h>

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    int arr[] = {1, 3, 4, 6, 7, 8, 11, 14, 15, 19};
    int len = 10;
    int val = 9;

    clock_t t1;
    clock_t t2;

    t1 = clock();
    binsearch1(val, arr, len);
    t1 = clock() - t1;

    t2 = clock();
    binsearch2(val, arr, len);
    t2 = clock() - t2;

    double time1 = ((double)t1) / CLOCKS_PER_SEC;
    double time2 = ((double)t2) / CLOCKS_PER_SEC;

    printf("binsearch1 took %f seconds to execute.\n"
	    "binsearch2 took %f seconds to execute.\n",
	    time1, time2);
}


/* Original binsearch */

int binsearch1(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high) {
	mid = (low + high) / 2;

	if (x < v[mid])
	    high = mid - 1;
	else if (x > v[mid])
	    low = mid + 1;
	else
	    return mid;
    }

    return -1;
}


/* binsearch with only one test inside the loop (this specific version is less efficient) */

int binsearch2(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high && v[mid] != x) {
	mid = (low + high) / 2;

	if (x < v[mid])
	    high = mid - 1;
	else
	    low = mid + 1;
    }

    if (v[mid] == x)
	return mid;
    else {
	return -1;
    }
}
