//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h> 
//#define MAX 100
//
//void merge_sort(int list[], int left, int right);
//void merge(int list[], int left, int mid, int right);
//void print_list(int* list, int n, char* mesg);
//
//void main() {
//	int list[] = { 32, 15, 20, 55, 40, 10, 27, 30, 70, 60, 50, 90, 66, 33 }, n;
//
//	n = sizeof(list) / sizeof(int);
//
//	print_list(list, n, "데이터 리스트 \n");
//	merge_sort(list, 0, n - 1);
//	print_list(list, n, "합병된 데이터 리스트: \n");
//}
//
//void merge_sort(int a[], int left, int right) {
//	int mid;
//	if (left < right) {
//		mid = (left + right) / 2;
//		merge_sort(a, left, mid);
//		merge_sort(a, mid + 1, right);
//		merge(a, left, mid, right);
//	}
//}
//
//void merge(int a[], int left, int mid, int right) {
//	int i = left, j = mid + 1, k = left, h; // 왼쪽 배열의 인덱스는 i, 오른쪽 배열의 인덱스는 j로 설정
//	// 합병된 리스트를 저장할 tlist
//	int tlist[MAX];
//
//	// 두 배열의 원소를 비교하면서 하나의 배열로 정렬하는 과정
//	while (i <= mid && j <= right) {
//		if (a[i] <= a[j]) {
//			tlist[k] = a[i];
//			i++; k++;
//		}
//		else {
//			tlist[k] = a[j];
//			j++; k++;
//		}
//	}
//	if (i > mid) // 왼쪽 리스트가 모두 처리되서, i = mid + 1이 되면, 오른쪽 리스트를 순서대로 처리
//		while (j <= right) tlist[k++] = a[j++];
//	else // 반대로 오른쪽 리스트가 모두 처리되서, j = right + 1이 되면, 왼쪽 리스트를 순서대로 처리
//		while (i <= mid) tlist[k++] = a[i++];
//	for (h = left; h <= right; h++) {
//		a[h] = tlist[h];
//	}
//}
//
//void print_list(int* list, int n, char* mesg) {
//	int i;
//
//	printf(mesg);
//	for (i = 0; i < n; i++) {
//		printf("%d ", list[i]);
//		if ((i % 7) == 6) printf("\n");
//	}
//	printf("\n\n");
//}
