#include "SeqStack.h"
void initStack(SeqStack& S) {
	S.elem = (SElemType*)malloc(initSize * sizeof(SElemType));
	if (S.elem == NULL) { printf("ƒ⁄¥Ê∑÷≈‰¥ÌŒÛ°£\n"); exit(1); }
	S.maxSize = initSize; S.top = -1;
}
bool Push(SeqStack& S, SElemType x) {
	if (S.top == S.maxSize - 1) { printf("’ª¬˙°£\n"); return false; }
	S.elem[++S.top] = x;
	return true;
}
bool Pop(SeqStack& S, SElemType x) {
	if (S.top == - 1) { printf("’ªø’°£\n"); return false; }
	x = S.elem[S.top--]; return true;
}
void OverflowProcess(SeqStack& S) {
	SElemType* temp = (SElemType*)malloc(2 * S.maxSize * sizeof(SElemType));
	if (temp == NULL) { printf("¥Ê¥¢ø’º‰∑÷≈‰ ß∞‹°£"); exit(1); }
	for (int i = 0; i <= S.top; i++) temp[i] = S.elem[i];
	free(S.elem);
	S.maxSize = 2 * S.maxSize; S.elem = temp;

}

