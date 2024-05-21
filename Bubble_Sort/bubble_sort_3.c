#define _CRT_SECURE_NO_WARNINGS
#define INUM 100
#include <stdlib.h>
#include <stdio.h>

void bubble(int a[], int n);
void printList(int a[], int n);
void swap(int* a, int* b);

main() {
	int a[INUM] = { 48, 17, 86, 2, 100, 25, 33, 52, 37, 70, 12, 27, 91, 16 };
	int i = 0;
	printf("정렬 전 데이터: ");

	while (a[i] != 0 && i < INUM) {
		printf("%d ", a[i]);
		i++;
	}

	printf("\n");

	bubble(a, i);

	printf("정렬 후 데이터: ");
	for (int j = 0; j < i; j++) {
		printf("%d ", a[j]);
	}
}

void bubble(int a[], int n) {
	int i = n - 1, j, tmp, cycle = 1, flag = 1;

	while (flag && i != 0) {
		printf("Cycle %d\n", cycle);
		flag = 0;
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) { // 정렬이 되지 않은 값이 있을 때,
				flag = 1; // flag를 1로 설정
				// tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; // 값 교환
				swap(&a[j], &a[j + 1]);
				printList(a, n);
			} // if
		} // for
		i--;
		cycle++;
		printf("\n");
	} // while
	printf("i = %d :: flag = %d\n", i, flag);
}

void printList(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}