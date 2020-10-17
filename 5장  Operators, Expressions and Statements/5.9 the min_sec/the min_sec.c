#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SEC_PER_MIN 60			// seconds in a minutes
int main(void)
{
	int sec, min, left;

	printf("Convert seconds to minutes and seconds!\n");
	scanf("%d", &sec);				// read numver of seconds
	while (sec > 0)
	{
		min = sec / SEC_PER_MIN;  // truncated number of minutes
		left = sec % SEC_PER_MIN; // number of seconds left over
		printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
		printf("Enter next value (<=0 to quit):\n");
		scanf("%d", &sec);

	}
	printf("Done!\n");

	return 0;
