#include "LinkList.h"


//头插法创建链表：参数n为节点个数，返回链表头指针
LinkList creatListHead(int n)
{
	LinkList head = NULL;         //创建头结点
	for (int i = 0; i < n; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));  //分配内存
		if (newNode == NULL) {
			puts("内存申请失败！");
			exit(1);
		}
		printf("请输入第%d个节点的值：", i + 1);
		scanf_s("%d", &newNode->data);
		newNode->next = head;  //将新节点的next指针指向当前头结点
		head = newNode;        //将头结点指针更新为新节点
	}
	return head;
}
//尾插法创建链表：参数n为节点个数，返回链表头指针
LinkList creatListTail(int n)
{
	LinkList head = NULL;  //创建头指针
	Node* tail = NULL;    //创建尾指针
	for (int i = 0; i < n; i++) {
		//分配内存
		Node* newNode = (Node*)malloc(sizeof(Node));
		if (newNode == NULL) {
			puts("内存申请失败！");	
			exit(1);
		}
		printf("请输入第%d个节点的值：", i + 1);
		scanf_s("%d", &newNode->data);
		newNode->next = NULL;  //将新节点的next指针置空

		if (head == NULL) {//如果链表为空，将新的节点作为头结点和尾结点
			head = newNode;
			tail = newNode;
		}
		else { //如果链表不为空，将新节点添加到尾部，并更新尾指针
			tail->next = newNode; //将当前尾结点的next指针指向新节点
			tail = newNode;       //将尾指针更新为新节点
		}
	}
	return head;
}

void printList(LinkList head)
{
	if (head == NULL) {
		puts("链表为空！");
		return;
	}
	Node* p = head; //创建一个指针p，避免更改头结点指针
	puts("链表中的元素为：");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next; //将指针p移动到下一个节点
	}
	printf("\n");
}
int main(void) {
	int n, i, j;
	int x, y;

	puts("请输入链表节点的个数：");
	if(scanf_s("%d", &n) != 1 || n < 0) {
		puts("输入无效，请输入一个非负整数！");
		return 1;
	}

	//头插法
	printf("使用头插法创建链表：\n");
	LinkList head1 = creatListHead(n);
	printList(head1);
	puts("请输入插入位置和要插入的值");
	if (scanf_s("%d %d", &i,&x) != 2|| n < 1) {
		puts("输入无效，请输入正整数！");
		return 1;
	}
	Insert(head1, i, x);
	printList(head1);
	//尾插法
	printf("使用尾插法创建链表：\n");
	LinkList head2 = creatListTail(n);
	printList(head2);
	puts("请输入删除位置：");
	if (scanf_s("%d", &j) != 1 || n < 1) {
		puts("输入无效，请输入一个正整数！");
		return 1;
	}
	Remove(head2, j, y);
	printf("删除的值为：%d\n", y);
	printList(head2);

	return 0;
 }
