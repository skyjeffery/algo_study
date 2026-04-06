#include <stdio.h>
#include <stdlib.h>
typedef int SElemType;
typedef struct node {
	SElemType data;
	struct node* link;
}LinkNode ,*LinkList,*LinkStack;

void initStack(LinkStack& S);

bool Push(LinkStack& s, SElemType x);

bool Pop(LinkStack& s, SElemType& x);

void printStack(LinkStack& s);

void creatLinkStack(LinkStack& s, SElemType A[], int n);
