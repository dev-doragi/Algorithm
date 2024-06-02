//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h> 
//#define MAX 100
//
//int merge(int* a1, int* a2, int* a, int n1, int n2);
//void print_list(int list[], int n, char* mesg);
//
//main() {
//	int list1[] = { 10, 20, 30, 40, 50, 60, 70, 77, 80, 90 };
//	int list2[] = { 25, 27, 35, 38, 40 };
//	int list3[] = { 15, 45, 47, 57, 59 };
//	int list4[] = { 1, 2, 5, 9, 60, 62, 65, 67, 69 };
//	int tlist1[50], tlist2[50], list[100];
//	int n1, n2, n3, n4, dnum1, dnum2, dnum;
//
//	n1 = sizeof(list1) / sizeof(int);
//	n2 = sizeof(list2) / sizeof(int);
//	n3 = sizeof(list3) / sizeof(int);
//	n4 = sizeof(list4) / sizeof(int);
//
//	dnum1 = merge(list1, list2, tlist1, n1, n2);
//	print_list(tlist1, dnum1, "중간 데이터 리스트1\n");
//	dnum2 = merge(list3, list4, tlist2, n3, n4);
//	print_list(tlist2, dnum2, "중간 데이터 리스트2\n");
//
//	dnum = merge(tlist1, tlist2, list, dnum1, dnum2);
//	print_list(list, dnum, "최종 합병 리스트\n");
//}
//
//void print_list(int a[], int n, char* mesg) {
//	int i;
//
//	printf(mesg);
//	for (i = 0; i < n; i++) {
//		printf("%d ", a[i]);
//		//if ((i % 10) == 9) printf("\n"); // 줄 바꿈
//	}
//	printf("\n\n");
//}
//
//int merge(int* a1, int* a2, int* a, int n1, int n2) {
//	int i = 0, j = 0, k = 0;
//
//	while (i < n1 && j < n2) {
//		if (a1[i] <= a2[j]) a[k++] = a1[i++];
//		else if (a1[i] > a2[j]) a[k++] = a2[j++];
//	}
//
//	if (i == n1)
//		while (j < n2) a[k++] = a2[j++];
//	else
//		while (i < n1) a[k++] = a1[i++];
//
//	return k;
//}