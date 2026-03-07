#include <stdio.h>
#define SQUARES 64
void format(void);
void skip(void);
int main(void)
{
	printf("1.格式化输出\n");
	format();
	printf("==========================\n");
	printf("2.*修饰\n");
	skip();

	return 0;
}
void format(void)
{
	const double CROP = 2E16;
	double total, current;
	int count = 1;

	printf("squares     added grains"
		"    total grains      fraction of world\n");
	total = current = 1.0;
	while(count <= SQUARES)
	{
		printf("%4d %15.2e %15.2e %17.2e\n", count, current, total, total / CROP);
		current *= 2;
		total += current;
		count++;
	}
}
void skip(void)
{
	int n;
	unsigned width, precision;
	double weight = 266.88;

	//跳过输入项
	printf("Please enter three integers.\n");
	if (scanf_s("%*d, %*d, %d", &n) != 1)
		printf("输入错误，请输入整数。\n");
	printf("The last integer is %d\n", n);

	//宽度和精度
	printf("Please enter width and precision.\n");
	if (scanf_s("%u %u", &width, &precision)!=1)
		printf("输入错误，请输入整数。\n");
	printf("The weight is %*.*f\n", width, precision, weight);
}