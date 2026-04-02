/*动态分配数组*/
#include <stdio.h>
#include <stdlib.h>  //为malloc() 、free()提供原型

int main(void)
{
	double* ptd;
	int max, number;
	int i = 0;

	puts("What is the maximum number of type double entries?\n");
	if (scanf_s("%d", &max) != 1)
	{
		puts("Numbers not correctly entered.\n");
		exit(EXIT_FAILURE);
	}
	else
		puts("Great!\n");
	/*ptd指向有max个元素的动态数组*/
	ptd = (double*)malloc(max * sizeof(double));
	//返回数组起始元素的地址
	if (ptd == NULL)
	{
		puts("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter the values(q to quit).\n");
	while (i < max && scanf_s("%lf", &ptd[i]) == 1)
		++i;
	printf("Here are your %d entries.\n", number = i);
	//定义number
	for (i = 0; i <number; i++)
	{
		printf("%6.2f", ptd[i]);
		if (i % 7 == 6)
			putchar('\n');
	}
	if (i % 7 != 0)
		putchar('\n');
	puts("Done!");
	free(ptd);

	return 0;
}


