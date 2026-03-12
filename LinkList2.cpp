#include "LinkList.h"

bool Insert(LinkList& first, int i, dataType x)
{//将新元素x插入到链表的第i个位置上，i从1开始计数
	if (i < 0) { puts("插入位置不合法！"); return false; }
	//创建新节点
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode){puts("内存申请失败！");exit(1);}
	newNode->data = x; //将新节点的数据域赋值为x
	if (first == NULL || i== 1){//如果链表为空或插入位置为第1个位置，将新节点作为新的头结点
		newNode->next = first;first = newNode;return true;
	}
	else {
		Node* p = first, * q = NULL;int k = 1;
		while (p!=NULL && k<i) {
			q = p; p = p->next; k++;
		}
		q->next = newNode; newNode->next = p; return true;
	}
}
/*  &：C++ 中的引用符号，表示 first 是一个链表对象的引用，
函数内部对 first 的修改会直接作用于原变量。*/
bool Remove(LinkList& first, int i,dataType &x)
{//删除链表的第i个位置上的元素，并将其值保存在x中，i从1开始计数
	Node * p, * q,*pr; int k;
	if (first == NULL || i < 0) { x = -1; return false; }
	if (i == 1) { q = first; first = first->next; }
	else {
		p = first; pr = NULL; k = 1;
		while (p != NULL && k < i) { pr = p; p = p->next; k++; }
		if (p == NULL) { x = -1; return false; }
		q = p; pr->next = p->next;
	}
	x = q->data; free(q);
	return true;
		
}

void clearList(LinkList& first)
{//清空链表，释放所有节点的内存
	Node* p = first, * q;
	while (p != NULL) {
		q = p; p = p->next; free(q);
	}
	first = NULL;
}



