//传递结构的地址and传递结构
#include<stdio.h>
#include<string.h>
#define FUNDLEN 50
#define NLEN 30
struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
struct names {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

void get_showinf(struct names* pst);

double sum(struct funds x);

char* s_gets(char* st, int n);

int main(void)
{
	struct names person;
	struct funds money ={
		"Center Bank",4904.00,
		"People Bank",54.64
	};

	get_showinf(&person);
	printf("而且，你一共有￥%.2lf\n", sum(money));

	
}
void get_showinf(struct names* pst)  //传递指向结构的指针
{
	puts("请输入你的名.");
	s_gets(pst->fname, NLEN);
	puts("请输入你的姓.");
	s_gets(pst->lname, NLEN);
	pst->letters = strlen((*pst).fname) + strlen(pst->lname);
	printf("%s %s, 你的名字一共有%d个字符.\n",
		pst->lname, pst->fname, pst->letters);
}
double sum(struct funds x)      //传递结构
{
	return x.bankfund + x.savefund;
}
char* s_gets(char* st, int n)
{//从标准输入读取最多 n-1 个字符到字符串 st 中。
	char* ret_val;
	char* find; 

	ret_val = fgets(st, n, stdin);//出错或读到EOF，则为NULL。
	//读到换行符或者超过字符数组的容量，fgets均会自动停止.
	//fgets 会保留换行符
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
/*传递指针：速度快但要用const 保护数据
  传递结构：处理原始数据的副本*/