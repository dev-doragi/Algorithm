//#define _CRT_SECURE_NO_WARNINGS
//#define INUM 100
//#include <stdlib.h>
//#include <stdio.h>
//
//void bubble(int a[], int n);
//
//main() {
//	int a[INUM] = { 12, 17, 25, 33, 48, 52, 86, 37, 100, 70 };
//	int i = 0;
//	printf("정렬 전 데이터: ");
//
//	while (a[i] != NULL) {
//		printf("%d ", a[i]);
//		i++;
//	}
//
//	printf("\n");
//
//	bubble(a, i);
//
//	printf("정렬 후 데이터: ");
//	for (int j = 0; j < i; j++) {
//		printf("%d ", a[j]);
//	}
//}
//
//void bubble(int a[], int n) {
//	int i = n - 1, j, tmp, flag = 1;
//
//	while (flag && i != 0) {
//		flag = 0;
//		for (j = 0; j < i; j++) {
//			if (a[j] > a[j + 1]) {
//				flag = 1;
//				tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp;
//			} // if
//		} // for
//		i--;
//	} // while
//
//	printf("i = %d :: flag = %d\n", i, flag);
//}