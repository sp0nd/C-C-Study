#include <stdio.h>
int main(void)
{
	int feet, fathoms;

	fathoms = 27;
	feet = 6 * fathoms;
	printf("there are %d feet in %d fathoms!\n", feet, fathoms);
	printf("yes, I said %d feet!\n", 6 * fathoms);

	return 0;
}
