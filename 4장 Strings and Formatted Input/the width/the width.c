#include <stdio.h>
#define PAGES 959
#define FPAGES 959.959
#define STR "asd"
int main(void)
{
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);
	printf("%10.4f\n", FPAGES);
	printf("%3s\n", STR);

	return 0;
}