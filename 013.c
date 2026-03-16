/*使用枚举类型的值*/
#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#define LEN 30

enum spectrum{ red,orange,yellow,green,blue,violet};//枚举符(int)类型
const char* colors[] = { "red","orange","yellow","green","blue","violet" };//字符串数组

char* s_gets(char* st, int n);

int main(void)
{
	char choice[LEN];
	enum spectrum color; //声明枚举型变量color;
	bool color_is_found = false;

	puts("请输入一个颜色，空行则退出。");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
			switch (color)
			{
			case red:puts("樱桃是红色的。");
				break;
			case orange:puts("橘子是橙色的。");
				break;
			case yellow:puts("香蕉是黄色的。");
				break;
			case green:puts("草是绿色的。");
				break;
			case blue:puts("天空是蓝色的。");
				break;
			}
		else
			puts("我并不知到你输入的颜色。");
		color_is_found = false;
		puts("请输入一个颜色，空行则退出。");
	}
	puts("祝你好运！");

	return 0;

}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;

}