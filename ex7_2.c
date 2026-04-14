#include <stdio.h>
#include<stdlib.h>	
int main(void) {
	int rows, cols; printf("请输入行数和列数：");
	if (scanf_s("%d%d", &rows, &cols) != 2||rows!=cols) { printf("输入错误"); return 1; }
	int** arr = (int**)malloc(rows * sizeof(int*));
	if (arr == NULL) { printf("内存发分配失败!"); return 1; }
	int i, j;

	for (i = 0; i < rows; i++) {
		arr[i] = (int*)malloc(cols * sizeof(int));
		if (arr[i] == NULL) { printf("第%d行内存分配失败", i); }
		for (j = 0; j < cols; j++) {
			if (i == j) {
				arr[i][j] = 1;
			}
			else if (i > j) { arr[i][j] = 6 - i + j; }
			else { arr[i][j] = j - i + 1; }
		}
	}printf("array:");
	for (i = 0; i < rows; i++) {
		printf("\n   ");
		for (j = 0; j < cols; j++) {
			printf("%-3d", arr[i][j]);
		}
	}
	for (i = 0; i < rows; i++) { free(arr[i]); }
	free(arr);

	return 0;

}