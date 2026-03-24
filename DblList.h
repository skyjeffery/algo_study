#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
typedef int Datatype;
typedef struct node {                          //循环双链表的定义
	Datatype data;                             
	int freq;                                   //访问次数
	struct node* rLink, * lLink;                //后继节点，前驱节点 的指针
}DblNode,*DblList;                             //表节点，双链表指针定义

void initDList(DblList& first);

void createDList(DblList& first, Datatype A[], int n);

void printDList(DblList& first, int d);

DblNode* search(DblList& first, Datatype x, int d);

DblNode* Locate(DblList& first, int i, int d);

bool Insert(DblList& first, int i, Datatype x, int d);

bool Remove(DblList& first, int i, Datatype& x, int d);
