#include<stdio.h>
void mikado(int);
int main(void)
{
	int pooh = 2, bah = 5;
	printf("in main(), pooh = %d and &pooh= %p\n", pooh, &pooh);
	printf("in main(), bah = %d and &bah = %p\n", bah, &bah);

	mikado(pooh);

	return 0;

}

void mikado(int bah)
{
	int pooh = 10;

	printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);

	return;

}// 같은 변수라도 값이 달라지면 주소가 달라진다.
