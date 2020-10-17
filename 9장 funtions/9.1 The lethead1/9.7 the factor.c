#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long fact(int n);
long rfact(int n);

int main(void)
{
	int num;
	
	printf("This program calculates factorials.\n");
	printf("Enter a value in the range 0-12 ()qto quit : \n");
	while (scanf("%d", &num) == 1)
	{
		if (num < 0)
			printf("No negative number, please.\n");
		else if (num > 12)
			printf("Keep input under 13.\n");
		else
		{
			printf("loop: %d facterial = %1d\n", num, fact(num));
			printf("recursion: %d factorial = %1d\n", num, rfact(num));

		}
		printf("Enter a value in the rang 0-12(q to quit:\n)");

	}
	printf("Bye.\n");

	return 0;

}

long fact(int n)
{
	long ans;

	for (ans = 1; n > 1; n--)
	{
		ans *= n;			// ans = ans*n;

		printf("%d\n", n);
	}
	return ans;
}

long rfact(int n)
{
	long ans;
	{
	if (n > 0)
	
		ans = n * rfact(n - 1);
	else
		ans = 1;
	printf("%d\n", n);
	}
	return ans;
}