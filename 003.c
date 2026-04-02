#include <stdio.h>
int count = 0; //文件作用域，外部链接
void report_count();
void accumulate(int k);
int main(void)
{
	int value;       // 自动变量
	register int i;  // 寄存器变量

	printf("Please enter an postive integer(0 to quit):");
	while (scanf_s("%d", &value) == 1 && value > 0)
	{
		++count;     //使用文件作用域变量
		for (i = value; i >= 0; i--)
			accumulate(i);
		printf("Please enter an postive integer"
			"(0 to quit)");
	}
	report_count();

	return 0;
}

void report_count()
{
	printf("Loop executed %d times.\n", count);
}