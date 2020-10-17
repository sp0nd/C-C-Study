#include<stdio.h>
int main(void)
{
	int n = 0;
	size_t intsize;

	intsize = sizeof(int);
	printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof n, intsize );

	double d = 0.0;
	size_t dsize;

	dsize = sizeof(double);
	printf("d = %f, d has %zd bytes; all ints have %zd bytes.\n", d, sizeof d, dsize);

	return 0;

}

