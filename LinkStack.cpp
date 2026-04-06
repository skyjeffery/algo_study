#include "LinkStack.h"
int main(void) {
	LinkStack S;
	int A[] = { 38,74,93,79,46,83,56 };
	int e=0;
	puts("==========链式栈==========");
	initStack(S);
	creatLinkStack(S, A, 7);
	printStack(S);
	if(Push(S, 68) && Pop(S, e))
	printf("弹出元素：%d\n", e);
	printStack(S);

	return 0;
}
void initStack(LinkStack& S) {
	S = (LinkNode*)malloc(sizeof(LinkNode));
	if (S == NULL) { printf("内存分配失败！"); exit(1);}
	S->link = NULL;
}

bool Push(LinkStack& s, SElemType x) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL) { printf("内存分配失败。"); return false; }
	p->data = x; p->link = s->link; s->link = p;//新节点指向原来的栈顶，top上移
	return true;
}

bool Pop(LinkStack& s, SElemType& x) {//存栈顶元素，栈顶指针退到次栈顶
	if (s->link == NULL) { printf("栈空。"); return false; }
	LinkNode* p = s->link; x = p->data;
	s->link = p->link; free(p);
	return true;
}

void printStack(LinkStack& s) {
	for (LinkNode* p = s->link; p != NULL; p = p->link)
		printf("%d  ", p->data);
	printf("\n");
}

void creatLinkStack(LinkStack& s, SElemType A[], int n) {
	LinkList p;
	for (int i = 0; i < n; i++) {
		p = (LinkNode*)malloc(sizeof(LinkNode));
		if (p == NULL) { printf("内存分配失败。"); }
		p->data = A[i]; p->link = s->link; s->link = p;
	}
}