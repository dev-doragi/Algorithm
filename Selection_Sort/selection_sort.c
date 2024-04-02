#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h> 

void selection_sort(int list[], int n);
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
	selection_sort(list, amt);
	printf("==================================================\n");

	printf("Sorted List: ");
	print_list(list, amt);
}

void selection_sort(int list[], int n) {
	int s, m, j, tmp;

	for (s = 0; s < n - 1; s++) {
		m = s;

		for (j = s + 1; j < n; j++)
			if (list[j] < list[m]) m = j;

		tmp = list[s];
		list[s] = list[m];
		list[m] = tmp;

		printf("Cycle %d: ", s + 1);

		print_list(list, n);
	}
}

void print_list(int list[], int n)
{
	printf("{ ");

	for (int i = 0; i < n; i++) {
		if (i + 1 == n)
			printf("%d", list[i]);
		else
			printf("%d, ", list[i]);
	}

	printf(" }\n");
}
