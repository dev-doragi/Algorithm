#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int binary_search_up(int a[], int n, int key);
int binary_search_down(int a[], int n, int key);
void selection_sort_up(int a[], int n);
void selection_sort_down(int a[], int n);
char compare(int x, int y);
void print_list(int list[], int n);

main() {
	int list[] = { 10, 120, 30, 40, 5, 90, 77, 25, 45, 100 };
	int n = sizeof(list) / sizeof(int); // �迭 list�� ��� ���� ����� �� ����!!
	int key, i;
	int sort_kind; // �������� or ��������

	printf("Present list = ");
	print_list(list, n);
	printf("Chose the sorting algorithm. (1.Ascending 2.Decending) ");
	scanf("%d", &sort_kind);

	if (sort_kind == 1) selection_sort_up(list, n);
	else if (sort_kind == 2) selection_sort_down(list, n);
	printf("Enter a key: ");
	scanf("%d", &key);

	if (sort_kind == 1) i = binary_search_up(list, n, key);
	else i = binary_search_down(list, n, key);
	if (i != -1)
		printf("%d is found. The index is [%d]\n", key, i);
	else
		printf("%d is not found\n", key);
}

int binary_search_up(int a[], int n, int key) {
	int mid;
	int left = 0, right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		switch (compare(key, a[mid])) { // compare �Լ��� ���� ���� ���� switch ���� ����
		case '>': left = mid + 1; break;
		case '<': right = mid - 1; break;
		case '=': return mid;
		}
	}
	return -1;
}

int binary_search_down(int a[], int n, int key) {
	int mid;
	int left = 0, right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		switch (compare(key, a[mid])) { // compare �Լ��� ���� ���� ���� switch ���� ����
		case '<': left = mid + 1; break;
		case '>': right = mid - 1; break;
		case '=': return mid;
		}
	}
	return -1;
}

void selection_sort_up(int list[], int n) {
	int s, min, j, tmp;

	for (s = 0; s < n - 1; s++) { // n-1 ������ �ݺ��ϴ� ������ ������ ������ ���� �ִ밪�̱� ������ ������ �ʿ䰡 ����.
		min = s; // ���� ���� �ε����� ������ min�� ���� ù��° �ε��� ���� ������ s�� ����

		for (j = s + 1; j < n; j++)
			if (list[j] < list[min]) min = j; // min �� ����

		tmp = list[s];
		list[s] = list[min];
		list[min] = tmp;

		printf("Cycle %d: ", s + 1);

		print_list(list, n);
	}
}

void selection_sort_down(int list[], int n) {
	int s, max, j, tmp;

	for (s = 0; s < n - 1; s++) { // n-1 ������ �ݺ��ϴ� ������ ������ ������ ���� �ִ밪�̱� ������ ������ �ʿ䰡 ����.
		max = s; // ���� ���� �ε����� ������ min�� ���� ù��° �ε��� ���� ������ s�� ����

		for (j = s + 1; j < n; j++)
			if (list[j] > list[max]) max = j; // max �� ����

		tmp = list[s];
		list[s] = list[max];
		list[max] = tmp;

		printf("Cycle %d: ", s + 1);

		print_list(list, n);
	}
}

char compare(int x, int y) {
	if (x > y) return '>';
	else if (x < y) return '<';
	else return '=';
}

void print_list(int list[], int n)
{
	printf("{ ");

	int i = 0;
	while (i < n - 1) {
		printf("%d, ", list[i++]); // ���� �����ڷ� ����Ʈ �� ���� �� ����
	}
	printf("%d", list[i]);

	printf(" }\n");
}