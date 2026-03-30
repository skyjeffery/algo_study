#include<stdio.h>
#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* createList(int arr[], int len);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(void) {
	int arr1[] = { 3, 5, 6, 7 };
	int arr2[] = { 2, 4, 3 }; // 示例第二个链表
	struct ListNode* l1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
	struct ListNode* l2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));
	struct ListNode* first = addTwoNumbers(l1, l2);
	// 打印链表
	struct ListNode* p = first;
	printf("相加结果链表：");
	while (p != NULL) {
		printf("%d -> ", p->val);
		p = p->next;
	}
	printf("NULL");
	free(l1); free(l2);
	return 0;

}

struct ListNode* createList(int arr[], int len) {
	if (len == 0) return NULL;
	// 头节点
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = arr[0];
	head->next = NULL;
	struct ListNode* tail = head; // 尾指针，尾插法

	for (int i = 1; i < len; i++) {
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = arr[i];
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
	return head;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head = NULL; struct ListNode* tail = NULL;
	int carry = 0; //进位值
	while (l1 || l2) {//l1与l2至少有一个为非空。
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;
		if (!head) { // 指针head为空
			head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
			tail->val = sum % 10;
			tail->next = NULL;
		}
		else {
			tail->next = malloc(sizeof(struct ListNode));
			tail->next->val = sum % 10;
			tail = tail->next;
			tail->next = NULL;
		}
		carry = sum / 10;
		if (l1) { l1 = l1->next; }
		if (l2) { l2 = l2->next; }
	}
	if (carry > 0) {
		tail->next = malloc(sizeof(struct ListNode));
		tail->next->val = carry;
		tail->next->next = NULL;
	}
	return head;
}