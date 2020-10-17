#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)

{
	float height;
	char name[32]="";

	printf("name & height :");
	scanf("%s, %f", name, &height);
	printf("you are %5.2f meter\n", height);
	printf("And your name %3s", name);

	return 0;

}
