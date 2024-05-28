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
	printf("���� �� ������: ");

	while (a[i] != 0 && i < INUM) {
		printf("%d ", a[i]);
		i++;
	}

	printf("\n");

	bubble(a, i);

	printf("���� �� ������: ");
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
			if (a[j] > a[j + 1]) { // ������ ���� ���� ���� ���� ��,
				flag = 1; // flag�� 1�� ����
				// tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp; // �� ��ȯ
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