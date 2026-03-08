#include<stdio.h>
#include<stdlib.h>
#include"diceroll.h"
#include<time.h>

int main(void)
{
	int dice, roll, sides, status;

	srand((unsigned int)time(0));
	printf("Enter the number of sides per dice.(0 to quit)\n");
	while (scanf_s("%d", &sides) == 1 && sides > 1)
	{
		printf("How many dices?\n");
		if ((status = scanf_s("%d", &dice)) != 1)
		{
			if (status == EOF)
				break;
			else
			{
				printf("You should have entered an integer.\n");
				while (getchar() != '\n')
					continue;
				printf("How many sides?Enter 0 to stop.\n");
				continue;
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d-sided dice.\n", roll,
			dice, sides);
		printf("How many sides ?Enter 0 to quit.\n");
	}
	printf("The rollem() function has been called %d times.\n", roll_count);
	printf("Good Fortune To You!\n");

	return 0;
}
