#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int ch;
	FILE* fp;
	unsigned long count = 0;
	if(argc != 2)
	{
		printf("Usage: %s fillename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL);// fp=fopen() >> 파일 이름 "r"(읽기)>> 종류             "r"읽기 and "w" 쓰기
	{
		printf("Can't opn %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", argv[1], count);

	system("pause");
	return 0;
}
