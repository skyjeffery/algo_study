#include <stdio.h>
void toobig(void);
void print2(void);
void charcode(void);
void print3(void);
int main(void)
{
	int x = 100;
	char name[100];

	printf("dec=%d;octal=%o;hex=%x\n", x, x, x);
	printf("dec=%d;octal=%#o;hex=%#x\n", x, x, x);
	//On PC, the most common settings:
	//long long 64bit ; long 32bit ; short 16bit ; int 32bit or 16bit
	printf("Type int has a size of %zd bytes.\n", sizeof(int));
	printf("Please enter your name"
		"________\b\b\b\b\b\b\b\b");
	toobig();
	print2();
	print3();

	return 0;
}
void toobig(void)
{
	//go back start point
	int i = 2147483647;
	unsigned int j = 4294967295;

	printf("%d %d %d\n", i, i + 1, i + 2);
	printf("%u %u %u\n", j, j + 1, j + 2);

}
void print2(void)
{
	unsigned int un = 300000000000;
	short end = 3000;
	long big = 653377;
	long long verybig = 46464494663863;

	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and not %u\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig = %lld and not %ld\n", verybig, verybig);
}
void charcode(void)
{
	char ch;//×Ö·û³£Á¿ and ×Ö·û´®

	printf("Please enter an integer.\n");
	scanf_s("%c", &ch);
	printf("The code for %c is %d.\n", ch, ch);
}
void print3(void)
{
	float a = 4500.0;
	double b = 2.14e7;
	long double c = 5.47e-5;

	printf("%f can be written %e.\n", a, a);
	printf("%f can be written %e.\n", b, b);
	printf("%Lf can be written %Le.\n", c, c);
}