#include "CircQuene.h"
int main(void) {
	char A[] = "hello";
	CircQueue Q;
	char c;
	initQueue(Q);
		for (int i = 0; i < strlen(A); i++) { enQueue(Q, A[i]); }
		if(getFront(Q, c)) printf("队头：%c.\n=====循环队列=====\n", c);
		printQueue(Q);
	return 0;
}
void initQueue(CircQueue& Q) {
	Q.elem = (QElemType*)malloc(queSize * sizeof(QElemType));
	if (Q.elem == NULL) { printf("内存分配失败。"); exit(1);}
	Q.maxSize = queSize; Q.front = 0; Q.rear = 0;
}

bool QueueEmpty(CircQueue& Q) { return Q.front == Q.rear; }

bool QueueFull(CircQueue& Q) { return (Q.rear + 1) % Q.maxSize == Q.front; }

int QueueSize(CircQueue& Q) { return (Q.rear - Q.front + Q.maxSize) % Q.maxSize; }

bool enQueue(CircQueue& Q, QElemType x) {
	if (QueueFull(Q))return false;
	Q.elem[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Q.maxSize;
	return true;
}

bool deQueue(CircQueue& Q, QElemType& x) {
	if (QueueEmpty)return false;
	x = Q.elem[Q.front];
	Q.front = (Q.front + 1) % Q.maxSize;
	return true;
}

bool getFront(CircQueue& Q, QElemType& x) {
	if (QueueEmpty(Q)) return false;
	x = Q.elem[Q.front];
	return true;
}

void printQueue(CircQueue& Q) {
	for (int i = Q.front; i < Q.rear; i = (i + 1) % Q.maxSize)
		printf("%c ", Q.elem[i]);
	printf("\n");
}