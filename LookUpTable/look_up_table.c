#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 500
#include <stdio.h>
#include <stdlib.h>

long stocksum(long s[][2], int n);
long lookup(long pdb[][2], int n, long item_code);
void display_table(long pdb[][2], int n);

void main(int argc, char* argv[]) {
	FILE* pricedb;
	long pdb[MAX_NUM][2], item_code, item_price;
	int i = 0, n, num, total_price = 0, amt = 0;;

	if ((pricedb = fopen(argv[1], "r")) == NULL) {
		printf("파일을 읽을 수 없습니다.\n");
		exit(1);
	}

	while (fscanf(pricedb, "%ld %ld", &(pdb[i][0]), &(pdb[i][1])) != EOF) {
		i++;
	}

	n = i;

	printf("오늘 팔린 물품의 종류는 몇 개인가요? : ");
	scanf("%d", &num);

	display_table(pdb, n);

	i = 0;
	
	while (i < num) {
		printf("물품코드와 팔린 갯수를 입력하세요. : ");
		scanf("%ld %ld", &item_code, &amt);
		total_price += lookup(pdb, n, item_code) * amt;
		i++;
	}

	printf("오늘의 정산금액: %d\n", total_price);
	printf("모든 물품의 가격: %ld\n", stocksum(pdb, n));
}

long stocksum(long s[][2], int n) {
	long sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += s[i][1];
	}
	return sum;
}

long lookup(long pdb[][2], int n, long item_code) {
	int i;
	for (i = 0; i < n; i++) {
		if (pdb[i][0] == item_code) {
			// 매칭되는 아이템 코드를 찾았을 때
			printf("%ld %ld\n", pdb[i][0], pdb[i][1]);
			return pdb[i][1];  // 해당 아이템의 가격을 반환
		}
	}
	// 아이템 코드에 매칭되는 것을 찾지 못한 경우
	printf("해당 아이템이 존재하지 않습니다.\n");
	return 0;  // 아무 값이나 반환 (일치하는 가격이 없을 때 0 반환)
}

void display_table(long pdb[][2], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%ld %ld\n", pdb[i][0], pdb[i][1]);
}