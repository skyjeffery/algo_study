#include <stdio.h>
int main(void) {
	int i,j,n=0;
	int flag;

	for (i = 2; i <= 100; i++) {
		flag = 1;
		for (j = 2; j < i; j++) {
			if (i % j == 0) { flag = 0; break; }
		}if (flag) {
			printf("%-4d", i);
			n++; if (n % 5 == 0)printf("\n");
		}
		
		
	}

	return 0;
}