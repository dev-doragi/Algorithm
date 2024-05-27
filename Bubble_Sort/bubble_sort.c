#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h> 

void bubbleSort(int a[], int n);
void swap(int* a, int* b);

main() {
	int list[MAX] = { 23, 42, 55, 12, 93, 22, 15, 83, 44, 82, 65 };
	bubbleSort(list, 11);

	for (int i = 0; i < 11; i++) {
		printf("%d ", list[i]);
	}
}

void bubbleSort(int a[], int n) { 
    int i, j, flag = 1;

    for (i = 0; i < n - 1 && flag; i++) { // 정렬이 완료된 인덱스를 나타내는 반복 
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
    }
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}