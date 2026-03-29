#include "part2.h"

void question5(LinkList& first) {
	DataType A[SIZE];
	LinkNode* s;

	first = (LinkNode*)malloc(sizeof(LinkNode));
	first->link = NULL;
	puts("请输入五个数。");
	for (int i = 0; i < SIZE; i++) {
		if (scanf_s("%d", &A[i]) != 1) { puts("输入错误。"); exit(1); }
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = A[i];
		s->link = first->link; first -> link = s;
	}
	puts("打印链表：");
	printList(first);
	puts("在中间位置插入数520。");
	if(!insert_LinkList(first, 3, 520)) puts("插入错误。");
	
}

void printList(LinkList& current) {
	if (current == NULL) { puts("单链表为空。"); exit(1); }
	printf("%d ", current->data);
	printList(current->link);
}

bool insert_LinkList(LinkList&first,int i, DataType x) {
	if (i < 0 || first == NULL) return false;
	LinkNode* p = first->link, * pr = first; int k = 1;
	while (p != NULL && k < i) {
		pr = p; p = p->link; k++;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (!s) { puts("内存分配错误。"); exit(1); }
	pr->link = s; s->link = p; s->data = x;
	return true;

}
