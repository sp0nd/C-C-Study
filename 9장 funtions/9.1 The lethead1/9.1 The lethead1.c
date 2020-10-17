#include <stdio.h>
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megavuck Plaza"
#define PLACE "Megapolios, CA 94904"
#define WIDTH 20

void starbar(void); 

int main(void)
{
	
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbar();

	return 0;

}

void starbar(void)
{
	int count;

	for (count = 1; count <= WIDTH; count++)
		putchar('*');
	putchar('\n');

}