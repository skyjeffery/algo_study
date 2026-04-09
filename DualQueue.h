#include <stdio.h>
#include <stdlib.h>
#define maxSize 10
typedef int QElemType;
typedef struct {
	int front[2], rear[2];
	QElemType elem[maxSize];
}DualQueue;

void initSize(DualQueue& Q);

bool queueFull(DualQueue& Q, int i);

bool queueEmpty(DualQueue& Q, int i);

bool enQueue(DualQueue& Q, int i, QElemType x);

bool deQueue(DualQueue& Q, int i, QElemType& x);

void printQueue(DualQueue& Q, int i);
