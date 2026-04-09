#include "DualQueue.h"

int main(void){
	int A[10] = { 38,74,93,79,46,83,56,40,52,93 };
	DualQueue Q; int n ;
	initSize(Q);
	if (enQueue(Q, 0,A[3]) && enQueue(Q, 1, A[7])) {
		printQueue(Q, 1);
	}
	deQueue(Q, 0, n);
	printf("%d\n", n);
	return 0;
}

void initSize(DualQueue& Q) {//初始化
	Q.front[0] = Q.rear[0] = 0;
	Q.front[1] = Q.rear[1] = maxSize / 2;
}

bool queueFull(DualQueue& Q,int i) {
	return Q.rear[i] == Q.front[1 - i];
}

bool queueEmpty(DualQueue& Q, int i) {
	return Q.rear[i] == Q.front[i];
}

bool enQueue(DualQueue& Q, int i, QElemType x) {
	if (i < 0 || i>1) { printf("队列号输入错误.\n"); return false; }
	if (Q.rear[i] == Q.front[1 - i]) {
		if (Q.rear[1 - i] == Q.front[i]) { printf("全满。\n"); return false; }
		int j = Q.rear[1 - i];
		while (j > Q.front[1 - i]) {//元素前移
			Q.elem[(Q.rear[1 - i] + 1) % maxSize] = Q.elem[j];
			j = (j - 1 + maxSize) % maxSize;
		}
		//指针前移
		Q.front[1 - i] = (Q.front[1 - i] + 1) % maxSize;
		Q.rear[1 - i] = (Q.rear[1 - i] + 1) % maxSize;
	}
	Q.rear[i] = (Q.rear[i] + 1) % maxSize;
	Q.elem[Q.rear[i]] = x;
	return true;
}

bool deQueue(DualQueue& Q, int i, QElemType& x) {
	if (queueEmpty(Q, i)) { printf("队列为空。\n"); return false; }
	Q.front[i] = (Q.front[i] + 1) % maxSize;
	x = Q.elem[Q.front[i]];
	return true;
}

void printQueue(DualQueue& Q,int i ) {
	// 1. 校验队列编号合法性
	if (i < 0 || i > 1) {
		printf("队列编号非法\n");
		return;
	}
	// 2. 判空：空队列直接提示并返回
	if (queueEmpty(Q, i)) {
		printf("队列%d为空\n", i);
		return;
	}
	// 3. 循环队列遍历逻辑（取模处理绕回）
	int pos = Q.front[i];
	while (true) {
		printf("%d ", Q.elem[pos]);
		// 遍历至队尾时终止（循环队列终止条件）
		if (pos == Q.rear[i]) {
			break;
		}
		pos = (pos + 1) % maxSize;  // 循环偏移
	}
	printf("\n");
}