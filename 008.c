/*用二进制I / O进行随机访问*/
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(void)
{
	double numbers[ARSIZE];
	double value;
	const char* file = "numbers.dat";
	long pos;
	int i;
	FILE* iofile;

	//创建一组double类型的值
	for (int i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + i * 3.0 + 1.0 / (i + 2);
	//尝试打开文件
	if (fopen_s(&iofile,file,"wb")!=0)
	{fprintf(stderr, "无法打开文件%s。", file); exit(1);}
	//以二进制格式把数组写入文件
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if (fopen_s(&iofile, file, "rb") != 0)
	{
		fprintf(stderr, "无法打开文件%s。", file); exit(1);
	}
	//从文件中读取选定的内容
	printf("请输入范围在0-%d的索引值。", ARSIZE - 1);
	while (scanf_s("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double);   // 计算偏移量
		fseek(iofile, pos, SEEK_SET);
		fread(&value, sizeof(double), 1, iofile);
		printf("该值为%lf\.", value);
		puts("请输入下一个索引值（超出范围则退出）");
	}
	fclose(iofile);
	puts("Done!");

	return 0;

}