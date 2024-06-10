#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct member {
	int id;
	char name[20];
	float score;
} example;

void over4(example* a, int n);
example find_max(example* a, int n);

main() {
	example onep, exmember[20];
	int i, n;
	printf("Input the number of data: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("데이터 입력: ");
		scanf("%d %s %f", &exmember[i].id, exmember[i].name, &exmember[i].score);
	}

	over4(exmember, n);
	onep = find_max(exmember, n);
	printf("Information of the highest score student = %d : %s : %.2f\n", onep.id, onep.name, onep.score);
}

void over4(example* a, int n) {
	printf("\n------학점이 4.0이상인 학생------\n");
	for (int i = 0; i < n; i++) {
		if (a[i].score >= 4.0) printf("%d %s.\n", a[i].id, a[i].name);
	}
	printf("\n");
}

example find_max(example* a, int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].score > a[max].score) max = i;
	}
	return a[max];
}