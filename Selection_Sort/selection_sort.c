#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h> 

void selection_sort_up(int list[], int n);
void print_list(int list[], int n);

void main() {
	int amt;

	printf("Input the amount of list.. ");
	scanf("%d", &amt);

	int list[MAX];
	printf("Input %d values in the list..", amt);
	for (int i = 0; i < amt; i++) 
		scanf(" %d", &list[i]);

	printf("Unsorted List: ");
	print_list(list, amt);

	printf("==================================================\n");
	selection_sort_up(list, amt);
	printf("==================================================\n");

	printf("Sorted List: ");
	print_list(list, amt);
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
