#include <stdio.h>
#include <stdlib.h>
typedef int QElemType;
typedef struct Node {//链式队列节点定义
	QElemType data;
	struct Node* link;
}LinkNode;
typedef struct {//链式队列定义
	LinkNode* front, * rear;
}LinkQueue;
