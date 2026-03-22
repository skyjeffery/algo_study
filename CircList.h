#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node {                        //循环链表的定义
	DataType data;                           //节点数据
	struct node* link;                       //后继节点的结构
}CircNode,*CircList,*CircListRear;
//CircList是有表头指针的带头结点的循环单链表
//CircListRear是没有表头指针只有表尾指针且不带头结点的循环单链表

bool insert(CircNode* first, int i, DataType x);

bool Remove(CircList& first, int i, DataType& x);
