#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>

typedef struct employee {
	long eid;
	char name[20];
	int escore;
	char dname[5];
} edatatype;

void quick_sorta(edatatype a[], int left, int right);
void quick_sortd(edatatype a[], int left, int right);

// 퀵정렬 오름차순
void quick_sorta(edatatype a[], int left, int right) {
	long pivot;
	int i, j;
	edatatype tmp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].eid; // pivot의 초기 값은 배열의 첫번째 요소로 지정

		// pivot 기준으로 큰 값과 작은 값의 인덱스를 저장하여 서로 위치를 바꾸는 반복문
		while (i < j) {
			// a[i].eid 값이 pivot보다 커질 때 또는 i 값이 right과 같아질 때 까지 반복
			do i++; while ((a[i].eid <= pivot) && (i < right)); 
			// a[j].eid 값이 pivot보다 작아질 때 또는 j 값이 left과 같아질 때 까지
			do j--; while ((a[j].eid >= pivot) && (j > left));

			// pivot 보다 작은 값은 왼쪽으로 가고, 큰 값은 오른쪽으로 가도록 값 교환
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

		// 이 부분을 잘 모르겠음
		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
		quick_sorta(a, left, j - 1);
		quick_sorta(a, j + 1, right);
	}
}

// 퀵정렬 내림차순
void quick_sortd(edatatype a[], int left, int right) {
	long pivot;
	int i, j;
	edatatype tmp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].escore;
		while (i < j) {
			// pivot 값을 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 보내야 한다.
			// pivot보다 큰 값의 인덱스를 저장
			do i++; while ((a[i].escore >= pivot) && (i < right));
			// pivot보다 작은 값의 인덱스를 저장
			do j--; while ((a[j].escore <= pivot) && (j > left));
			// 둘의 인덱스가 역전되지 않았을 때, (pivot 기준으로 나누기 때문에 둘의 인덱스가 역전되면 기준에 어긋남)
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

		// pivot 기준 왼쪽 오른쪽 파티션이 모두 나뉘게 되면, pivot 값을 left 값과 교환한다. -> pivot을 가운데로 옮기기
		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
		// pivot보다 작은 파티션과 큰 파티션에서 다시 퀵정렬 (Divide: 분할)
		quick_sortd(a, left, j - 1);
		quick_sortd(a, j + 1, right);
	}
}

main(int argc, char *argv[]) {
	edatatype edb[50];
	FILE* infile, * outfile;
	int i = 0, j;
	char choice;
	char dcode[5];

	if (argc != 3) {
		printf("실행 인수를 잘못 주었습니다.\n");
		exit(1);
	}

	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("입력 파일을 열 수 없습니다.\n");
	}

	if ((outfile = fopen(argv[2], "w")) == NULL) {
		printf("출력 파일을 열 수 없습니다.\n");
	}

	while (fscanf(infile, "%ld %s %d %s", &(edb[i].eid), edb[i].name, &(edb[i].escore), edb[i].dname) != EOF) i++;

	// 1. id의 오름차순으로 파일에 저장
	quick_sorta(edb, 0, i - 1);
	printf("\n\nSorted Data.... \n");

	for (j = 0; j < 1; j++)
		fprintf(outfile, "%ld\t%s\t%d\t%s\n", (edb[j].eid), edb[j].name, (edb[j].escore), edb[j].dname);

	// 2. dcode를 읽어 그 부서에 해당하는 사원정보 출력하기
	printf("Sales Department : S110\n");
	printf("Reasearch Department: R250\n");
	printf("Management Department: M210\n");
	printf("\nEnter the Deprartment code: ");
	scanf("%s", dcode); // char 타입 배열 dcode

	for (j = 0; j < i; j++) {
		if (strcmp(dcode, edb[j].dname) == 0) 
			printf("%ld\t%s\t%d\n", (edb[j].eid), edb[j].name, edb[j].escore);
	}

	// 3. 영어 성적이 큰 값부터 정보 출력하기
	printf("\n\nFrom the highest English score To the lowest....\n");

	quick_sortd(edb, 0, i - 1);
	for (j = 0; j < i; j++) 
		printf("%ld\t%s\t%d\t%s\n", (edb[j].eid), edb[j].name, (edb[j].escore), edb[j].dname);
}