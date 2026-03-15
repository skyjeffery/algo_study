#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITLE 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
	char title[MAXTITLE];
	char author[MAXAUTL];
	float value;
};

char* s_gets(const char* st, int n);

int main(void)
{
	struct book library[MAXBKS];  // 二维数组
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("无法打开文件book.dat.",stderr);
		exit(1);
	}

	rewind(pbooks);       /*定位到文件开始*/
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks))
	{
		if (count == 0)
			puts("文件books.dat中的内容为：");
		printf("%s by %s：￥%.2f\n", library[count].title,
			library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("该文件已满。", stderr);
		exit(2);
	}

	puts("请输入新的书籍标题：");
	puts("按[Enter]键退出");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITLE) != NULL
		&& library[count].title[0] != '\0')
	{
		puts("请输入该书的作者：");
		s_gets(library[count].author, MAXAUTL);
		puts("请输入该书的价钱：");
		if (scanf_s("%f", &library[count++].value) != 1)
			puts("输入错误，请重新输入;");
		while(getchar()!=1)
			continue;
		puts("请输入新的书籍标题：");
	}

	if (count > 0)
	{
		printf("这是书籍清单：");
		for (index = 0; index < count; index++)
			printf("%s by %s：￥%.2f\n", library[index].title,
				library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);

	}
	else
		put("没有一本书");
	puts("拜拜");
	return 0;
}

char* s_gets(const char* st, int n)
{
	char* ret_val;
	char* find;

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