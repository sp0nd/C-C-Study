#define _CRT_SCURE_NO_WARNINGS
#include<stdio.h>

#define PRAISE " You are an extraordinarybeing."
int main(void)
{
	char name[40]="";

	printf("What's your name?");
	scanf("%s", name);
	printf("Hello, %s. %s\n", name, PRAISE);

	return 0;
}
