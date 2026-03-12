#include <stdio.h>
#include<stdlib.h>
typedef int dataType;
typedef struct node {
	dataType data;           //数据域
	struct node* next;      //指针域
}Node, * LinkList;        //LinkNode是结构体类型，LinkList是指向结构体类型的指针类型

LinkList creatListHead(int n);

LinkList creatListTail(int n);

void printList(LinkList head);

bool Insert(LinkList& first, int i, dataType x);

bool Remove(LinkList& first, int i, dataType& x);

void clearList(LinkList& first)；
