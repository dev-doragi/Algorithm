#define _CRT_SECURE_NO_WARNINGS
#define INUM 100
#include <stdlib.h>
#include <stdio.h>

int bsearch_stock(unsigned a[][2], int n, unsigned key);
void print_item(char* heading, unsigned a[][2], int n);
void bubble(unsigned a[][2], int n);

void main(int argc, char* argv[]) {
	FILE* stockdb;
	unsigned stock[INUM][2], item_code;
	int k = 0, s;

	if ((stockdb = fopen(argv[1], "r")) == NULL) {
		printf("Cannot open read file... \n"); exit(1);
	}

	// 아이템 종류의 수를 저장
	while ((fscanf(stockdb, "%u %u", &stock[k][0], &stock[k][1])) != EOF) k++;

	print_item("임의로 저장된 물품코드: \n", stock, k);

	// 물품코드의 내림차순으로 정렬
	bubble(stock, k);
	print_item("내림차순으로 정렬된 물품코드: \n", stock, k);

	// 검색
	printf("검색할 item number 입력: ");
	scanf("%u", &item_code);
	s = bsearch_stock(stock, k, item_code);
	if (s == -1) printf("재고물품이 없습니다.\n");
	else printf("%u의 재고개수 = %u\n", stock[s][0], stock[s][1]);
}
void print_item(char* heading, unsigned a[][2], int n) {
	int i;
	printf(heading);
	for (i = 0; i < n; i++) printf("%u ", a[i][0]);
	printf("\n");
}

int bsearch_stock(unsigned a[][2], int n, unsigned key) { // 이진 탐색 진행
	int left = 0, right = n - 1, mid;

	while (left <= right) { // 왼쪽 값이 오른쪽 값보다 작을 때 반복
		mid = (left + right) / 2; // 중앙 값 설정
		if (key < a[mid][0]) left = mid + 1; // key 값이 mid 값보다 작을 때 -> key값은 mid보다 오른쪽에 있음
		else if (key > a[mid][0]) right = mid - 1; // key 값이 mid 값보다 클 때 -> key 값은 mid보다 왼쪽에 있음
		else return mid;
	} /* while */
	return -1;
} /* search */

void bubble(unsigned a[][2], int n) {
	int i = n - 1, j, flag = 1; // i는 배열의 끝 인덱스(정렬이 완료된 인덱스), j는 0부터 반복, flag는 정렬이 완료되있는 상태인지 확인용
	unsigned tmp; // tmp 변수 하나만 사용해도 상관X

	while (flag && i != 0) {
		flag = 0; // flag를 0으로 먼저 변경
		for (j = 0; j < i; j++) { // 배열의 마지막 인덱스 전까지
			if (a[j][0] < a[j + 1][0]) { // 만약 정렬이 안된 데이터가 있다면,
				flag = 1; // flag를 1로 변경
				tmp = a[j][0]; a[j][0] = a[j + 1][0]; a[j + 1][0] = tmp;
				tmp = a[j][1]; a[j][1] = a[j + 1][1]; a[j + 1][1] = tmp;
			} // if
		} // for
		i--; // 맨 마지막 요소부터 정렬이 완료되기 때문에 i값을 낮추며 반복한다.
	}
}