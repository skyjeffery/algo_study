#include"CircList.h"
bool insert(CircNode* first, int i, DataType x) {
	//将x插入在链表中第i个节点的位置
	if (i<= 0 || first ==NULL) return false;
	CircNode* p, * pr, * s;
	int count;
	p = first->link; pr = first; count = 1;
	while( p != first && count < i)
	{
		pr = p; p = p->link; count++;
	}//p指向第i个节点，pr指向第i-1个节点
	s = (CircNode*)malloc(sizeof(CircNode));
	s->data = x; pr->link = s; s->link = p;
	return true;
}

// 错误写法（无&）：函数内修改的是副本，外部链表不会变
bool Remove(CircList& first, int i, DataType& x) {
	//将链表中的第i个元素删除，通过应用参数x返回该元素的值
	if (first->link == first || i <= 0) return false;
	CircNode* p, * pr;
	int count;
	p = first->link; pr = first; count = 1;
	while(p !=first && count < i)
	{
		pr = p; p = p->link; count++;
	}
	if (p == first) return false;
	pr->link = p->link; x = p->data;
	free(p); return true;
}

void Josephus(CircList& js, int n, int m) {
	CircNode* p, * pr; int i, j;
	p= js->link ; pr = js;
	puts("\n当前报数趟数-删除的序号");
	for (i = 0; i < n - 1; i++) {
		if (p == js) { pr = p; p = p->link; }
		for (j = 0; j < m; j++) {
			pr = p; p = p->link;
			if (p == js) { pr = p; p = p->link; }
		}
		printf("%d-%d  ", i + 1, p->data);
		pr->link = p->link; free(p);
		p = pr->link;
	}
	printf("\n最后环中只剩下%d", p->data);
}

int main(void) {
	CircNode  *clist,*p,*q; int n = 8; int m = 3;
	int A[8] = { 1,2,3,4,5,6,7,8 };
	clist = (CircNode*)malloc(sizeof(CircNode));
	clist->data = A[0];
	clist->link = clist;
	q = clist;

	// 2. 循环创建剩余节点
	for (int i = 1; i < n; i++) {
		p = (CircNode*)malloc(sizeof(CircNode));
		p->data = A[i];
		p->link = clist; // 新节点指向头节点
		q->link = p;     // 前驱节点指向新节点
		q = p;           // 移动前驱指针
	}

	printf("游戏人数为%d,报数间隔为%d,报数序列为：", n, m);
	Josephus(clist, n, m);
	return 0;
}