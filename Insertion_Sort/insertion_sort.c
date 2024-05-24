#define _CRT_SECURE_NO_WARNINGS
#define INUM 100
#include <stdlib.h>
#include <stdio.h>

// 학번, 이름, 점수를 저장할 student 구조체 정의
typedef struct student {
	long id;
	char name[20];
	double score;
} sdatatype;

// 삽입 정렬은 이미 정렬되어 있는 데이터에 계속적으로 들어오는 데이터를 적절한 위치에 삽입하여 정렬을 유지하는 개념을 이용한다.
void insert_sort(sdatatype a[], int n);
void insert_sort1(sdatatype a[], int n);
void insert_sort2(sdatatype a[], int n);

main(int argc, char* argv[]) {
	sdatatype s[50];
	FILE* infile, * outfile;
	int i = 0, j;
	char choice;

	if (argc != 3) {
		printf("실행 인수를 잘못 주었습니다. \n");
		exit(1);
	}

	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("입력 파일을 열 수 없습니다. \n");
		exit(1);
	}

	if ((outfile = fopen(argv[2], "w")) == NULL) {
		printf("출력 파일을 열 수 없습니다. \n");
		exit(1);
	}

	// s[i].name은 s[i].name 배열의 첫번째 주소를 나타내므로 &를 붙이지 않는다.
	while (fscanf(infile, "%ld %s %lf", &(s[i].id), s[i].name, &(s[i].score)) != EOF) i++;

	printf("학번 순으로 저장하려면 1을 \n");
	printf("성적 순으로 저장하려면 2를 선택하시오:  ");

	scanf("%c", &choice);

	if (choice == '1') insert_sort(s, i);
	else if (choice == '2') insert_sort2(s, i);
	else {
		printf("선택번호를 잘못 입력하였습니다.");
		exit(1);
	}

	printf("정렬 결과\n");
	for (j = 0; j < i; j++) {
		printf("%ld\t%s%\t%.2f\n", (s[j].id), s[j].name, (s[j].score));
		fprintf(outfile, "%ld\t%s%\t%.2f\n", (s[j].id), s[j].name, (s[j].score));
	}

	printf("장비를 정지합니다.\n");
}

//void insert_sort(sdatatype a[], int n) {
//	int i, j;
//	sdatatype temp;
//
//	for (i = 1; i < n; i++) {
//		temp = a[i];
//		for (j = i - 1; j >= 0; j--) {
//			if (a[j].id > temp.id) a[j + 1] = a[j]; // 해당 조건이 거짓이어도 j 값이 감소하기 때문에 올바르지 않다.
//		}
//		a[j + 1] = temp;
//	}
//}

// 학번의 오름차순으로 정렬
void insert_sort(sdatatype a[], int n) {
	int i, j;
	sdatatype temp;

	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j].id > temp.id; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

// 학번의 오름차순으로 정렬
void insert_sort1(sdatatype a[], int n) {
	int i, j;
	sdatatype temp;

	for (i = 1; i < n; i++) { // 삽입정렬은 첫번째 요소를 이미 정렬된 상태로 간주하고 진행한다.
		temp = a[i]; // 현재 요소를 temp에 저장
		j = i - 1; // 현재 요소의 이전 인덱스
		while (a[j].id > temp.id && j >= 0) { // 이전 요소의 id 값이 현재 id 값보다 크고 j값이 음수가 아닐 때,
			a[j + 1] = a[j]; // 이전 요소의 값을 한칸씩 뒤로 밀기
			j--;
		}
		// while이 끝나면 a[j].id는 temp.id보다 작은 값이 된다.
		a[j + 1] = temp; // 한 칸씩 다 밀고 남은 자리에 temp 삽입
	}
}

// 성적의 내림차순으로 정렬 (가장 큰 값이 먼저)
void insert_sort2(sdatatype a[], int n) {
	int i, j;
	sdatatype temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while (a[j].score < temp.score && j >= 0) { // 이전 요소의 score 값이 현재 score 값보다 크고, j가 음수가 아닐 때,
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp; // 한 칸씩 다 밀고 남은 자리에 temp 삽입
	}
}