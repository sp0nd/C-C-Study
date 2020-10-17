#include<stdio.h>
int imax(int, int);

int main(void)

{
	

	printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3,5));
	printf("The maximun of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));

	return 0;
}

int imax(int n, int m)
{
	return (n > m ? n : m);//꼭 값이 아니라 수식이 될수도 있음

}


