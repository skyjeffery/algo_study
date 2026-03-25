#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {        //顺序表的动态存储表示
	DataType* data;
	int maxSize;
	int n;
}SeqList;

void question1(void);

void question2(SeqList& L);
