#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n=0;

	printf("Enter number : ");

	for (n = 0; 0 < n < 9; n++);
	{
		for (int m = 0; m < n + 1; m++)
			
		
		printf("%d ", m++);
		printf("\n");
	}
	return 0;

}