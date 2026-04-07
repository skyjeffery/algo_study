#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define queSize 7
typedef char QElemType;
typedef struct {            //循环队列的结构定义
	QElemType* elem;
	int maxSize;
	int front, rear;
}CircQueue;

void initQueue(CircQueue& Q);

bool QueueEmpty(CircQueue& Q);

bool QueueFull(CircQueue& Q);

int QueueSize(CircQueue& Q);

bool enQueue(CircQueue& Q, QElemType x);

bool deQueue(CircQueue& Q, QElemType& x);

bool getFront(CircQueue& Q, QElemType& x);

void printQueue(CircQueue& Q);
