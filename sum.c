//sum.c -- - A simple program to compute the sum of array elements.
#include <stdio.h>
#define SIZE 10
int sum(int ar[], int);
int sump(int*, int*);
int main(void)
{
	int marbles[SIZE] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 110 };
	long answer, asw;

	answer = sum(marbles, SIZE);
	printf("The total number of marbles is %ld.\n", answer);
	printf("The size of marbles is %zd bytes.\n", 
		sizeof(marbles));

	asw = sump(marbles, marbles + SIZE);
	printf("The total number of marbles is %ld.\n", asw);	
	printf("The size of marbles is %zd bytes.\n",
		sizeof(marbles));

	return 0;
}
//In this program, marbles is an array,and ar is a pointer to the first element of the array of marbles.
int sum(int ar[], int n)
{
	int i;
	int total = 0;

	for (i = 0; i < n; i++)
		total += ar[i];
	printf("The size of ar is %zd bytes.\n", sizeof(ar));

	return total;
}
int sump(int* start, int* end)
{
	int total = 0;

	while (start < end)
	{
		total += *start;
		start++;
	}

	return total;
}
