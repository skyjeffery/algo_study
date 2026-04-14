#include <stdio.h>

int main(void) {
	int arr[2][4],i,j;
	for (i=0;i < 2; i++) {
		for (j = 0; j < 4; j++) {
			if (scanf_s("%d", &arr[i][j]) != 1) { printf("ÊäÈë´íÎó¡£"); return 1; }
		}
	}
	printf("The adj you have input :");
	for (i = 0; i < 2; i++) {
		printf("\n   ");
		for (j = 0; j < 4; j++) {
			printf("%-4d", arr[i][j]);
		}
	}
	printf("\n");

	return 0;
}