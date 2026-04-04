#include <stdio.h>
#include <stdlib.h>
#define initSize 20
typedef int SElemType;
typedef struct {//动态顺序栈的结构定义
	SElemType* elem;
	int maxSize;
	int top;   //top表示栈顶，即最后一个元素的存储位置
}SeqStack;
//静态栈需要预先定义并且申请栈的存储空间

void initStack(SeqStack& S);

bool Push(SeqStack& S, SElemType x);

bool Pop(SeqStack& S, SElemType x);

void OverflowProcess(SeqStack& S);
