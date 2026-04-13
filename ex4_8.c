#include <stdio.h>
int main(void) {
	int m, n, i, c = 9;
	for (m = 1; m < 10; m++) {
		for (i = 0; i < c; i++) { printf(" "); }
		c += 9;
		for (n = m; n < 10; n++) {
			printf("%d * %d=%-2d ", m, n, m * n);
		}
		printf("\n");
	}

	return 0;
}