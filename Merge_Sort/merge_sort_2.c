#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define MAX 100

void print_list(int list[], int n, char* mesg);
void quick_sort(int a[], int left, int right);
int merge(int *a1, int *a2, int *a, int n1, int n2);

main() {
	int list1[] = { 32, 15, 20, 50, 40, 10, 22, 30 };
	int list2[] = { 25, 55, 17, 38, 13, 35, 12, 44 };
	int merged_list[100];
	int n1, n2, n;
	char sorted;

	n1 = sizeof(list1) / sizeof(int); // 각 리스트의 크기를 저장
	n2 = sizeof(list2) / sizeof(int);

	print_list(list1, n1, "list1의 요소: ");
	print_list(list2, n1, "list2의 요소: ");

	printf("\n list1이 정렬되어 있나요? (y/n)  ");
	sorted = getche();
	if (sorted == 'n') quick_sort(list1, 0, n1 - 1);

	printf("\n list2이 정렬되어 있나요? (y/n)  ");
	sorted = getche();
	if (sorted == 'n') quick_sort(list2, 0, n2 - 1);

	print_list(list1, n1, "\n\n정렬된 list1의 요소: ");
	print_list(list2, n1, "정렬된 list2의 요소: ");

	n = merge(list1, list2, merged_list, n1, n2);

	print_list(merged_list, n, "합병된 merged_list의 요소: ");
}

// 두 데이터 리스트를 합치는 함수 merge
int merge(int* a1, int* a2, int* a, int n1, int n2) {
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2) {
		if (a1[i] <= a2[j]) a[k++] = a1[i++];
		else if (a1[i] > a2[j]) a[k++] = a2[j++];
	}

	if (i == n1)
		while (j < n2) a[k++] = a2[j++];
	else
		while (i < n1) a[k++] = a1[i++];

	return k;
}

void quick_sort(int a[], int left, int right) {
	long pivot;
	int i, j;
	int tmp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left];
		while (i < j) {
			do i++; while ((a[i] <= pivot) && (i < right));
			do j--; while ((a[j] >= pivot) && (j > left));
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}
}

void print_list(int a[], int n, char* mesg) {
	int i;

	printf(mesg);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
		//if ((i % 10) == 9) printf("\n"); // 줄 바꿈
	}
	printf("\n\n");
}