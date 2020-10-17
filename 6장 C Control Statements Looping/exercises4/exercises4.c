#include<stdio.h>

int main(void)
{
	int ch = 'A';

	for (int n = 0; n < 6; n++)
	{
		for (int m = 0; m < n + 1; m++)
			printf("%c", ch++);
	printf("\n");
	}
	

	return 0;
}
