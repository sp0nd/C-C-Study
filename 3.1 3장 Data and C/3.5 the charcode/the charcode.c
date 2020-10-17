#include <stdio.h>
int main(void)
{
	char ch;

	printf("Please enter a chareacter.\n");
	scanf_s("%c", &ch);	/* user inputs character*/
	printf("The code for %c is %d, %x and %o.\n", ch, ch, ch);

	return 0;

}