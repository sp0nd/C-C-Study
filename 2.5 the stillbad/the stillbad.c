#include <stdio.h>
int main(void)
{
	int n, n2, n3;

	// this program has a semjantic error
	n = 5;
	n2 = n * n;
	n3 = n * n * n;
	printf("n= %d, n squared = %d, n cubed = %d\n");

	return 0;
}
