#include "DblList.h"

int main(void)
{
	int n = 8;
	int d;
	int A[SIZE];
	DblNode* first;

	puts("输入8个数 输入0则可退出");
	for (int i = 0; i < n; i++) {
		if (scanf_s("%d", &A[i]) != 1 || A[i] == 0) break;
	}
	puts("请输入d的值 ：d=0则前驱输出；d=1则后继输出");
	if (scanf_s("%d", &d) != 1) return 1;
	createDList(first, A, d);
	puts("循环双链表：");
	printDList(first, d);

	return 0;
}


void initDList(DblList& first) {
	first = (DblNode*)malloc(sizeof(DblNode));
	first->rLink = first; first->lLink = first;
}

void createDList(DblList& first, Datatype A[], int n) {
	initDList(first);
	DblNode* p = first, * q, * s;

	for (int i = 0; i < n; i++) {
		s = (DblNode*)malloc(sizeof(DblNode));
		s->data = A[i];
		q = p->rLink; s = q->lLink; s = p->rLink;   //前驱方向链接
		p->rLink = s; s->rLink = p; p = s;
	}
}

void printDList(DblList& first,int d) {
	//d=0则前驱输出；d=1则后继输出
	DblList p = (d == 0) ? first->lLink : first->rLink;
	while (p != first) {
		printf("%d ", p->data);
		p = (d == 0) ? p->lLink : p->rLink;
	}
	printf("\n");
}

DblNode* search(DblList& first, Datatype x, int d) {
	DblNode* p = (d == 0) ? first->lLink : first->rLink;
	while (p->data != x || p != first) {
		p = (d == 0) ? p->lLink : p->rLink;
	}
	return (p != first) ? p : NULL;
}

DblNode* Locate(DblList& first, int i, int d) {
	if (first->lLink == first || i <= 0)return NULL;
	DblNode* p = (d == 0) ? first->lLink : first->rLink;
	for (int j = 0; j < i; j++) {
		if (p == first) break;
		else p = (d == 0) ? p->lLink : p->rLink;
	}
	return (p != first) ? p : NULL;

}
bool Insert(DblList& first, int i, Datatype x, int d) {
	DblNode* p = Locate(first, i - 1, d);
	if (p == NULL)return false;
	DblNode* s = (DblNode*)malloc(sizeof(DblNode));
	s->data = x;
	if (d == 0)
	{
		s->lLink = p->lLink; p->lLink = s;
		s->lLink->rLink = s; s->rLink = p;
	}
	else {
		s->rLink = p->rLink; p->rLink = s;
		s->rLink->lLink = p; s->lLink = p;
	}
	return true;
}

bool Remove(DblList& first, int i, Datatype&x, int d) {
	DblNode* p = Locate(first, i, d);
	if (p == NULL || p == first) return false;
	p->rLink->lLink = p->lLink;
	p->lLink->rLink = p->rLink;
	x = p->data; free(p);
}
