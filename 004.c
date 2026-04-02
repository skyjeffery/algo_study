#include<stdio.h>
#include<math.h>
int main(void) {
	//找最大值
	int a, max, i=2;
	if (scanf_s("%d", &a) != 1) { puts("输入错误。"); return 1; }
	max = a;//变量一定先赋初值
	do {
		if (scanf_s("%d", &a) != 1) { puts("输入错误。"); return 1; }
		if (max < a) { max = a; }
		i++;
	} while (i <= 5);//执行4次
	printf("The max value is %d\n", max);

	//穷举法
	int x, y, z;
	for (x = 0; x < 20; x++) {
		for (y = 0; y < 34; y++) {
			z = 100 - x - y;
			if (5 * x + 3 * y + z / 3.0 == 100) {
				printf("x=%d,y=%d,z=%d\n", x, y, z);
			}
		}
	}

	//计算阶乘的和
	long sum = 0,t = 1;
	for (int z = 1; z < 10; z++) {
		t *= (long)z;
		sum += t;
	}
	printf("1!+2!+3!+...+10!=%ld", sum);
	

	//牛顿迭代法求解非线性方程
	double x1, x2, f1, f2;
	x2 = 2.5;
	do {
		x1 = x2;
		f1 = 3 * x1 * x1 * x1 - 9 * x1 * x1 + 4 * x1 - 12;
		f2 = 9 * x1 * x1 - 18 * x1 + 4;
		x2 = x1 - f1 / f2;
	} while (fabs(x2 - x1) >= 1e-5);
	printf("The root is %.2lf.", x2);

	return 0;
}

