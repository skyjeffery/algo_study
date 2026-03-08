#include <stdio.h>
#include <stdlib.h>
#include "diceroll.h"

int roll_count = 0;

static int rollem(int sides) /*该函数属于该文件私有*/
{
	int roll;

	roll = rand() % sides + 1; /*随机数在1到sides之间*/
	++roll_count; //掷骰子的总次数

	return roll;
}
int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;

	if(dice < 1 || sides < 2)
	{
		printf("你至少要掷一个骰子，且每个骰子至少有两面。\n");
		return -1;
	}

	for(d = 0; d < dice; d++)
		total += rollem(sides);

	return total; 
}