#include "part2.h"

int main(void)
{
	int max = 0,min = 0;
	SeqList L;
	L = question1();
	question3(L, &max, &min);
	question4(L, &max, &min);
	return 0;
}
SeqList question1(void) {
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
	return L;
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

void question3(SeqList& L,int *max,int *min) {//输出极值
	int i, n = L.n;
	//初始化max和min
	if (n % 2 == 1) { //奇数个元素
		*max = *min = L.data[0];
		i = 1;
	}
	else {
		if (L.data[0] > L.data[1]) {
			*max = L.data[0];
			*min = L.data[1];
		}
		else {
			*max = L.data[1];
			*min = L.data[0];
		}
		i = 2;
	}
	//成对比较
	while (i < n) {
		int big, small;
		if (L.data[i] > L.data[i + 1]) {
			big = L.data[i];
			small = L.data[i + 1];
		}
		else {
			big = L.data[i+1];
			small = L.data[i];
		}
		if (big > *max) *max = big;
		if (small < *min) *min = small;
		i += 2;
	}
	printf("\nmax=%d,min=%d", *max, *min);
}
void question4(SeqList& L, int* max, int* min) {
	for (int i = 0; i < L.n; i++) {
		if (L.data[i] > *min || L.data[i] < *max) {
			for (int j = i; j < L.n; j++) {
				L.data[j] = L.data[j + 1];
				L.n--;
			}
		}
	}
	for (int i = 0; i < L.n; i++) { printf("%d  ", L.data[i]); }

}
