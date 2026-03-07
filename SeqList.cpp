#include"SeqList.h"
void initList(SeqList& L);

void clearList(SeqList& L);

int Length(SeqList& L);

bool isEmpty(SeqList& L);

bool isFull(SeqList& L);

int Search(SeqList& L, DataType x);

bool Insert(SeqList& L, int i, DataType& x);

bool Remove(SeqList& L, int i, DataType x);

void createList(SeqList& L, DataType A[], int n);

void merge(SeqList& LA, SeqList& LB);

void intersection(SeqList& LA, SeqList& LB);

void initList(SeqList& L)
{
	//创建存储数组
	L.data = (DataType*)malloc(initSize * sizeof(DataType));
	if (!L.data) { printf("存储分配错误!\n"); exit(1); }
	L.maxSize = initSize; L.n = 0;
}
void clearList(SeqList& L) {
	L.n = 0;
}
int Length(SeqList& L) {
	return L.n;
}
bool isEmpty(SeqList& L) {
	return (L.n == 0) ? true : false;
}
bool isFull(SeqList& L) {
	return (L.n == L.maxSize) ? true : false;
}
int Search(SeqList& L, DataType x)
{
	if (isEmpty(L)) return -1;
	for (int i = 0; i < L.n; i++)
		if (L.data[i] == x) return i + 1;
		else return -1;
}
bool Insert(SeqList& L, int i, DataType& x) {
	if (isFull(L)) return false;
	if (i<1 || i>L.n + 1) return false;
	for (int j = L.n; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = x;
	L.n++; return true;
}
bool Remove(SeqList& L, int i, DataType x) {
	//删除第i个元素引用参数x返回删除元素
	if (isEmpty(L)) return false;
	if (i<1 || i>L.n)return false;
	x = L.data[i - 1];
	for (int j = i; j <= L.n; j++)
		L.data[j - 1] = L.data[j];
	L.n--; return true;	
}
void createList(SeqList& L, DataType A[], int n) {
	initList(L);
	for (int i; i < n; i++) L.data[i] = A[i];
	if (n > L.maxSize) L.maxSize = n;
	L.n = n;
}
void merge(SeqList& LA, SeqList& LB) {
	int m = Length(LA), n = Length(LB), i, k, x;
	for (i = 1; i <=n; i++) {
		x = LB.data[i - 1];
		k = Search(LA, x);
		if (k == -1) {
			Insert(LA, n + 1, x); n++;
		}
	}
}
void intersection(SeqList& LA, SeqList& LB) {
	int m = Length(LA), n = Length(LB), i, k, x;
	while (i <= n) {
		x = LB.data[i - 1];
		k = Search(LA, x);
		if (k == -1) {
			Remove(LB, i,x); n--;
		}
		else i++;
	}
}


