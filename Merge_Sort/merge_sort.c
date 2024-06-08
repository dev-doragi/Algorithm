#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define MAX 100

// left�� right�� ���� �迭�� ���� �ε���, �� �ε����� ��Ÿ����.
void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);
void merge_2(int list[], int left, int mid, int right);
void print_list(int* list, int n, char* mesg);

void main() {
	int list[] = { 32, 15, 20, 55, 40, 10, 27, 30, 70, 60, 50, 90, 66, 33 }, n;

	// n�� ũ��� list�� ũ��� ����.
	n = sizeof(list) / sizeof(int);

	print_list(list, n, "������ ����Ʈ \n");
	merge_sort(list, 0, n - 1);
	print_list(list, n, "�պ��� ������ ����Ʈ: \n");
}

// �ϳ��� �迭�� ���� ũ���� 2���� �κ� �迭�� �����Ѵ�. (����)
void merge_sort(int a[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);
		// ���ҵǾ� ���ĵ� �κ� ���յ��� �ϳ��� �պ��Ѵ�. (����)
		merge_2(a, left, mid, right);
	}
}

void merge(int a[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left; // ���� �迭�� �ε����� i, ������ �迭�� �ε����� j�� ����, k�� �պ��� �迭�� �ε���
	// �պ��� ����Ʈ�� ������ tlist
	int tlist[MAX];

	// �� �迭�� ���Ҹ� ���ϸ鼭 �ϳ��� �迭�� �����ϴ� ����
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			tlist[k++] = a[i++];
		}
		else {
			tlist[k++] = a[j++];
		}
	}
	if (i > mid) // ���� ����Ʈ�� ��� ó���Ǽ�, i = mid + 1�� �Ǹ�, ������ ����Ʈ�� ������� ó��
		while (j <= right) tlist[k++] = a[j++];
	else // �ݴ�� ������ ����Ʈ�� ��� ó���Ǽ�, j = right + 1�� �Ǹ�, ���� ����Ʈ�� ������� ó��
		while (i <= mid) tlist[k++] = a[i++];
	// �պ����ĵ� ����Ʈ�� a���ٰ� ����
	for (k = left; k <= right; k++) { // right�� �迭�� �� �ε����̹Ƿ� k<=right�� ������ �����ؾ� �迭�� �� �ε������� ��ȸ�Ѵ�!
		a[k] = tlist[k];
	}
}

void merge_2(int a[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	int tlist[MAX];

	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) tlist[k++] = a[i++];
		else tlist[k++] = a[j++];
	}
	if (i > mid) 
		while (j <= right) tlist[k++] = a[j++];
	else 
		while (i <= mid) tlist[k++] = a[i++];

	for (k = left; k < right; k++)
		a[k] = tlist[k];
}

void print_list(int* list, int n, char* mesg) {
	int i;

	printf(mesg);
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
		//if ((i % 7) == 6) printf("\n");
	}
	printf("\n\n");
}
