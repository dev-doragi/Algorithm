#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int cnt = 0;
void hanoi(int n, char a, char b, char c);

void main() {
	int n;
	printf("Input the number of disk: ");
	scanf("%d", &n);
	if (n <= 0)
		printf("\nIllegal number of disk!!\n");
	else
		hanoi(n, 'A', 'B', 'C');

	printf("Count: %d", cnt);
}

void hanoi(int n, char a, char c, char b) {
	if (n == 1) {
		printf("Move disk from %c to %c\n", a, c);
		cnt++;
	}
	else {
		hanoi(n - 1, a, b, c);
		hanoi(1, a, c, b);
		hanoi(n - 1, b, c, a);
	}
}