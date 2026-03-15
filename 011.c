//结构中指针存放字符串，用malloc分配内存比较合理

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
	long id;
	struct { char first[20]; char last[20]; }; //匿名结构
};

struct flex
{
	size_t count;
	double average;
	double scores[];  //伸缩形数组成员
};

void showFlex(const struct flex* p);

int main(void)
{
	struct person information;
	struct flex* pf;
	int n = 5;
	double total=0.0;

	information = (struct person){ 3250409058,{"Sam","Jeffery"}};//复合字面量，临时结构值
	printf("%s %s 的id 是%ld\n", information.last,
		information.first, information.id);

	//为结构和数组分配空间
	puts("请输入一个正整数:");
	if (scanf_s("%d", &n) != 1) {
		while (getchar() != '\n');
		puts("输入错误，请输入一个整数(空行则退出)");
		return 1;
	}
	pf = malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf == NULL)
	{
		puts("内存分配错误。"); return 1;
	}
	pf->count = n;
	for (int i =0;i<n;i++)
	{
		pf->scores[i] = 4.0 * i + i * 745 / 3;
		total += pf->scores[i];
	}
	pf->average = total / n;
	showFlex(pf);
	free(pf);
}
void showFlex(const struct flex* p)
{
	int i;
	printf("成绩：");
	for (i = 0; i < p->count; i++)
		printf("%lf ", p->scores[i]);
	printf("\n平均成绩：%lf", p->average);
}

