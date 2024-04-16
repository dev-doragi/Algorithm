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
	int n = sizeof(list) / sizeof(int); // 배열 list의 요소 수를 계산할 수 있음!!
	int key, i;
	int sort_kind; // 오름차순 or 내림차순

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
		switch (compare(key, a[mid])) { // compare 함수의 리턴 값에 따라 switch 구문 실행
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
		switch (compare(key, a[mid])) { // compare 함수의 리턴 값에 따라 switch 구문 실행
		case '<': left = mid + 1; break;
		case '>': right = mid - 1; break;
		case '=': return mid;
		}
	}
	return -1;
}

void selection_sort_up(int list[], int n) {
	int s, min, j, tmp;

	for (s = 0; s < n - 1; s++) { // n-1 전까지 반복하는 이유는 어차피 마지막 값은 최대값이기 때문에 정렬할 필요가 없다.
		min = s; // 가장 작은 인덱스를 저장할 min에 먼저 첫번째 인덱스 값을 저장한 s를 복사

		for (j = s + 1; j < n; j++)
			if (list[j] < list[min]) min = j; // min 값 갱신

		tmp = list[s];
		list[s] = list[min];
		list[min] = tmp;

		printf("Cycle %d: ", s + 1);

		print_list(list, n);
	}
}

void selection_sort_down(int list[], int n) {
	int s, max, j, tmp;

	for (s = 0; s < n - 1; s++) { // n-1 전까지 반복하는 이유는 어차피 마지막 값은 최대값이기 때문에 정렬할 필요가 없다.
		max = s; // 가장 작은 인덱스를 저장할 min에 먼저 첫번째 인덱스 값을 저장한 s를 복사

		for (j = s + 1; j < n; j++)
			if (list[j] > list[max]) max = j; // max 값 갱신

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
		printf("%d, ", list[i++]); // 후위 연산자로 리스트 값 참조 후 증가
	}
	printf("%d", list[i]);

	printf(" }\n");
}