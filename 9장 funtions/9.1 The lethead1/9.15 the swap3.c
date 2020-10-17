#include<stdio.h>
void interchange(int* u, int* v);

int main(void)
{
	int x = 5, y = 10;
	printf("Originally x = %d and y =%d.\n", x, y);
	printf("Originally x = %p and y =%p.\n", &x, &y);
	interchange(&x, &y);
	printf("Now x = %d and y = %d.\n", x, y);
	printf("Now x = %p and y = %p.\n", &x, &y);

	return 0;

}

void interchange(int* u, int* v)
{
	int temp;
	temp = *u; // temp gets value that u points to
	*u = *v;
	*v = temp;

	return ;
}