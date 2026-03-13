/*把文件附加到另一个文件末尾*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define BUFSIZE 4096
#define SLEN 81
void append(FILE* source, FILE* dest);
char* s_gets(char* st, int n);

int main(void) {
	FILE* fa, * fs;//fa 指向目标文件，fs 指向源文件
	int files = 0, ch;
	char file_dest[SLEN];  //目标文件名
	char file_sour[SLEN];  //源文件名

	puts("请输入目标文件的名称。");
	s_gets(file_dest, SLEN);
	if (fopen_s(&fa,file_dest,"a+") != 0)
	{fprintf(stderr, "无法打开%s\n", file_dest); exit(1);}
	//三大核心FILE*类型的指针: stderr,stdio,stdin;
	if (setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)
	{fputs("无法创建输出缓存\n", stderr); exit(1);}
	puts("请输入第一个源文件的名称（空行即退出）。");
	while (s_gets(file_sour, SLEN) && file_sour[0] != '\0')
	{
		if (strcmp(file_sour, file_dest) == 0)
			//从第一个字节开始，逐个字节对比ASCII值，若所有字符都相同且长度一致，返回0
			fputs("无法将文件添加给自己。", stderr);
		else if ((fopen_s(&fs,file_sour,"r")!=0))
			fprintf(stderr, "无法打开%s\n", file_sour);
		else {
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("无法创建输出缓存\n", stderr); continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "问题出现在%s源文件。\n", file_sour);
			if (ferror(fa) != 0)
				fprintf(stderr, "问题出现在%s目标文件。\n", file_dest);
			fclose(fs);
			files++;
			printf("文件%s已经添加.\n", file_sour);
			puts("请输入下一个文件名称。");
		}
	}
	printf("%d个文件已经全部添加完成。\n", files);
	rewind(fa);
	printf("%s 的内容：", file_dest);
	while ((ch = getc(fa)) != -1)
		putchar(ch);
	fclose(fa);

	return 0;

}




void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		//（fread/fwrite/sizeof/malloc）都返回 / 接收 size_t
		fwrite(temp, sizeof(char), bytes, dest);
}

char * s_gets(char*st,int n)
{//从键盘输入字符串，存储在st指向的数组中，最多接受n-1个字符，并在字符串末尾添加一个空字符
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); //查找换行符
		if (find)
			*find = '\0'; //如果地址不是NULL，就在此处放置一个空字符
		else
			while (getchar() != '\n')
				continue; //处理输入行过长的情况
	}
	return ret_val;
}

	
