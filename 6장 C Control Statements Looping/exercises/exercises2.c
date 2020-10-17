#include<stdio.h>
#define LAG 5
int main(void)
{
	int lag;
	int mon;

	for (int lag = 0; lag < LAG; lag++)
	{
		for (int mon = 0; mon < lag + 1; mon++)
			printf("$");
		printf("\n");
	}
	
	return 0;




}