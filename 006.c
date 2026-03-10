/*--包含多本书的图书目录*/
#include <stdio.h>
#include <string.h>
char* s_gets(char* st, int n);
#define MAXTITL 41
#define MAXNAME 31
#define MAXBOOKS 100

struct book {
	char title[MAXTITL];
	char author[MAXNAME];
	float value;
};

int main(void)
{
	struct book library[MAXBOOKS];
	int count = 0;

	puts("Please enter the book title.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBOOKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(library[count].author, MAXNAME);
		puts("Now enter the value.");
		scanf_s("%f", &library[count].value);
		while (getchar() != '\n')  //清理输入行中剩余的字符
			continue;
		count++;
		puts("Enter the next book title.");
	}
	if (count > 0)
	{
		puts("Here is the list of your books.");
		for (int i = 0; i <= count; i++)
			printf("%20s by %20s: %5.2f", library[i].title,
				library[i].author, library[i].value);
	}
	else
		puts("No books?That's so bad.");

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st,n,stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar != '\n')
				continue;
	}
	return ret_val;
}