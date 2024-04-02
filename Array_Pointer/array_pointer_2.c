#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pcount(int a[]);

main() {
	int data[10], k;

	printf("Enter 10 data: ");
	for (k = 0; k < 10; k++) {
		scanf("%d", data+k);
	}
	printf("양의 정수 개수는 %d\n", pcount(data));
}

int pcount(int data[]) {
	int j, result = 0;
	for (j = 0; j < 10; j++)
		if (data[j] > 0) result++;
	return result;
}