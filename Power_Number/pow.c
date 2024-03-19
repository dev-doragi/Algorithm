#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int MyPow(int x, int y);

main() {
	int k;

	for (k = 2; k < 6; k++) {
		printf("%d ** %d = %d\n", k, k + 1, MyPow(k, k + 1));
	}
}

int MyPow(int x, int y) {
	int i, ans = 1;

	for (i = 0; i < y; i++) ans *= x;
	return ans;
}