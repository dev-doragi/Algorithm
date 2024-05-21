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
	while ((fscanf(stockdb, "%u %u", &stock[k][0], &stock[k][1])) != EOF) k++;

	print_item("���Ƿ� ����� ��ǰ�ڵ�: \n", stock, k);

	// ��ǰ�ڵ��� ������������ ����
	bubble(stock, k);
	print_item("������������ ���ĵ� ��ǰ�ڵ�: \n", stock, k);

	// �˻�
	printf("�˻��� item number �Է�: ");
	scanf("%u", &item_code);
	s = bsearch_stock(stock, k, item_code);
	if (s == -1) printf("���ǰ�� �����ϴ�.\n");
	else printf("%u�� ����� = %u\n", stock[s][0], stock[s][1]);
}
void print_item(char* heading, unsigned a[][2], int n) {
	int i;
	printf(heading);
	for (i = 0; i < n; i++)printf("%u\n", a[i][0]);
}

int bsearch_stock(unsigned a[][2], int n, unsigned key) { // ���� Ž�� ����
	int left = 0, right = n - 1, mid;

	while (left <= right) { // ���� ���� ������ ������ ���� �� �ݺ�
		mid = (left + right) / 2; // �߾� �� ����
		if (key < a[mid][0]) left = mid + 1; // key ���� mid ������ ���� �� -> 
		else if (key > a[mid][0]) right = mid - 1;
		else return mid;
	} /* while */
	return -1;
} /* search */

void bubble(unsigned a[][2], int n) {
	int i = n - 1, j, flag = 1; // i�� �迭�� �� �ε���, j�� 0���� �ݺ�
	unsigned tmp; // tmp ���� �ϳ��� ����ص� ���X

	while (flag && i != 0) {
		flag = 0;
		for (j = 0; j < i; j++) {
			if (a[j][0] < a[j + 1][0]) {
				flag = 1;
				tmp = a[j][0]; a[j][0] = a[j + 1][0]; a[j + 1][0] = tmp;
				tmp = a[j][1]; a[j][1] = a[j + 1][1]; a[j + 1][1] = tmp;
			} // if
		} // for
		i--;
	}
}