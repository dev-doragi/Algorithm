//#define _CRT_SECURE_NO_WARNINGS
//#define MAX 100
//#include <stdio.h> 
//
//void bubbleSort(int a[], int n);
//void swap(int* a, int* b);
//
//main() {
//	int list[MAX] = { 23, 42, 55, 12, 93, 22, 15, 83, 44, 82, 65 };
//	bublleSort(list, 11);
//
//	for (int i = 0; i < 11; i++) {
//		printf("%d ", list[i]);
//	}
//}
//
//void bublleSort(int a[], int n) {
//	int i = n - 1, j, tmp;
//
//	while (i != 0) {
//		for (j = 0; j < i - 1; j++) {
//			if (a[j] > a[j + 1]) {
//				swap(a[j], a[j + 1]);
//			}
//		}
//		i--;
//	}
//}
//
//void swap(int* a, int* b) {
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}