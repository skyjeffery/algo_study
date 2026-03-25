#include "part2.h"

int main(void)
{
	question1();
	return 0;
}
void question1(void) {
	SeqList L;
	DataType A[5];
	L.data = (DataType*)malloc(10 * sizeof(DataType));
	if (L.data == NULL) { puts("内存分配错误。"); exit(1); }
	L.maxSize = 10; L.n = 0;
	puts("请随即输入5个整数。(确保有两个相同)");
	for (int i=0; i < 5; i++) {
		if (scanf_s("%d", &A[i]) != 1) { puts("请重新输入。"); exit(1); }
		L.data[i] = A[i];
	}
	L.n = 5; printf("顺序表：\n");
	for (int i=0; i < L.n; i++) { printf("%d  ", L.data[i]); }
	puts("\n倒序输出：\n");
	for (int i=0; i < L.n; i++) { printf("%d  ", L.data[L.n-i-1]); }
	puts("\n从小到大输出(删除重复值）:\n");
	question2(L);
}

void question2(SeqList& L) {
	
	int temp;

	//冒泡排序
	for (int i = 0; i < L.n - 1; i++) {
		for (int j = 0; j < L.n - i - 1; j++) {
			if (L.data[j] > L.data[j + 1]) {
				temp = L.data[j];
				L.data[j] = L.data[j+1];
				L.data[j + 1] = temp;
			}
		}
	}

	// 去重（排序后执行）
	int k = 0;
	for (int i = 0; i < L.n; i++) {
		if (i == 0 || L.data[i] != L.data[i - 1]) {
			L.data[k++] = L.data[i];
		}
	}
	L.n = k; // 更新有效长度

	for (int i = 0; i < L.n; i++) { printf("%d  ", L.data[i]); }


}
