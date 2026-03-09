//存储一本书的图书目录
#include<stdio.h>
#include<string.h>
char * s_gets(char* st, int n);
#define MAXTITL 41       //标题的最大长度为40
#define MAXNAME 31       //作者名字的最大长度为30

struct book {
	char title[MAXTITL];
	char name[MAXNAME];
	float values;
};

int main(void)
{
	struct book library;

	puts("Enter the book title.");
	s_gets(library.title, MAXTITL);
	puts("Enter the book name.");
	s_gets(library.name, MAXNAME);
	puts("Enter the value this book.");
	scanf_s("%f", &library.values);
	printf("%s by %s: $%.2f.\n", library.title, library.name, library.values);
	puts("Done!.\n");

	return 0;
}

char * s_gets(char* st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
