#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define M_P_H 60
int main(void)
{
	int M, H;
	printf("Covert minutes to hours!\n");
	scanf("%d", &M);
	while (M > 0)
	{
		H = M / M_P_H;
			printf("%d minutes is %d\n", M, H);
			printf("Enter next value(<=0 to quit):\n");
			scanf("%d", &M);

	}
	printf("Done!\n");

	return 0;
}