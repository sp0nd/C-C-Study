#include <stdio.h>
int main(void)
{
	int num;

	printf("Please enter a number.\n");
	scanf_s("%d", &num);  /* user inputs character*/
	printf("The num is %d --> %c.\n", num, num);

	return 0;

}