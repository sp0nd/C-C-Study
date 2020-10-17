#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MIN_PER_SEC 60       // minute in a seconds
int main(void)
{
	int min, sec;

	printf("Convert minutes to seconds and seconds!\n");
	scanf("%d", &min);          //read numver of minutes
	while (min > 0)
	{
		sec = min * MIN_PER_SEC;
		printf("%d minutes is %d seconds.\n", min, sec);
		printf("Enter next value(<=0 to quit):\n");
		scanf("%d", &min);

	}
	printf("Done!\n");

	return 0;

}

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define                    
int main(voif)
{ 
	int */