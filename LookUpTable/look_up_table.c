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
		printf("������ ���� �� �����ϴ�.\n");
		exit(1);
	}

	while (fscanf(pricedb, "%ld %ld", &(pdb[i][0]), &(pdb[i][1])) != EOF) {
		i++;
	}

	n = i;

	printf("���� �ȸ� ��ǰ�� ������ �� ���ΰ���? : ");
	scanf("%d", &num);

	display_table(pdb, n);

	i = 0;
	
	while (i < num) {
		printf("��ǰ�ڵ�� �ȸ� ������ �Է��ϼ���. : ");
		scanf("%ld %ld", &item_code, &amt);
		total_price += lookup(pdb, n, item_code) * amt;
		i++;
	}

	printf("������ ����ݾ�: %d\n", total_price);
	printf("��� ��ǰ�� ����: %ld\n", stocksum(pdb, n));
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
			// ��Ī�Ǵ� ������ �ڵ带 ã���� ��
			printf("%ld %ld\n", pdb[i][0], pdb[i][1]);
			return pdb[i][1];  // �ش� �������� ������ ��ȯ
		}
	}
	// ������ �ڵ忡 ��Ī�Ǵ� ���� ã�� ���� ���
	printf("�ش� �������� �������� �ʽ��ϴ�.\n");
	return 0;  // �ƹ� ���̳� ��ȯ (��ġ�ϴ� ������ ���� �� 0 ��ȯ)
}

void display_table(long pdb[][2], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%ld %ld\n", pdb[i][0], pdb[i][1]);
}