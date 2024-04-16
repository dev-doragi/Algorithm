#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 15

void make_msquare(int table[][MAX_SIZE], int n);
void display(int table[][MAX_SIZE], int n);

void main() {
	int n, r, c, sum = 0;
	int table[MAX_SIZE][MAX_SIZE];

	printf("Input the size of table..");
	scanf("%d", &n); 
	if (n < 1 || n > MAX_SIZE) { // n�� ������ �ùٸ��� ���� ��,
		printf("Error! size is out of range!\n");
		exit(0);
	}

	if (n % 2 == 0) { // n�� ���� ¦���� ��,
		printf("Error! size is even!\n");
		exit(0);
	}

	// 2���� �迭 table�� �ʱ�ȭ
	for (r = 0; r < n; r++) 
		for (c = 0; c < n; c++) 
			table[r][c] = 0;

	make_msquare(table, n);
	display(table, n);

	for (c = 0; c < n; c++) 
		sum += table[0][c];
	
	printf("Row/Column/Diagonal Sum = %d\n", sum);

}

void make_msquare(int table[][MAX_SIZE], int n) {
	int r, c, digit, row, col;

	// ù��° ���� �߾��� 1�� ����
	r = 0; c = (n - 1) / 2;
	table[r][c] = 1;

	// ������ ��Ģ�� ���� ���̺� ä���
	for (digit = 2; digit <= n * n; digit++) {
		row = r - 1; // ���� ��
		col = c - 1; // ���� ��
		if (row < 0) row = n - 1; // up, �迭�� ������ ������ �ݴ������� �̵�
		if (col < 0) col = n - 1; // left
		if (table[row][col]) r++; // �ش� ��ġ�� ���� �̹� ������ ���� ������ �̵�
		else {
			r = row; 
			c = col;
		}
		table[r][c] = digit; // �ش� ��ġ�� �� �ֱ�
	}
}

void display(int table[][MAX_SIZE], int n) {
	int r, c;

	for (r = 0; r < n; r++) {
		if (r == 0) {
			printf("  ");
			for (int i = 0; i < 5 * (n + 1) - 2; i++) { // = ������ 5(n+1) - 2
				printf("=");
			}
			printf("\n");
		}
			
		for (c = 0; c < n; c++) {
			if (c == 0) printf("||");
			printf("%5d", table[r][c]);
			if (c == n - 1) printf("   ||");
		}
		printf("\n");

		if (r == n-1) {
			printf("  ");
			for (int i = 0; i < 5 * (n + 1) - 2; i++) { // = ������ 5(n+1) - 2
				printf("=");
			}
			printf("\n");
		}
	}
}