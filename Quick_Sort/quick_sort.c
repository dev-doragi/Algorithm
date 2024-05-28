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

void quick_sorta(edatatype a[], int left, int right) {
	long pivot;
	int i, j;
	edatatype tmp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].eid;
		while (i < j) {
			do i++; while ((a[i].eid <= pivot) && (i < right)); // a[i].eid ���� pivot���� Ŀ�� �� �Ǵ� i ���� right ���� Ŀ�� �� ���� �ݺ�
			do j--; while ((a[j].eid >= pivot) && (j > left));
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

		// �� �κ��� �� �𸣰���
		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
		quick_sorta(a, left, j - 1);
		quick_sorta(a, j + 1, right);
	}
}

void quick_sortd(edatatype a[], int left, int right) {
	long pivot;
	int i, j;
	edatatype tmp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].escore;
		while (i < j) {
			do i++; while ((a[i].escore >= pivot) && (i < right));
			do j--; while ((a[j].escore <= pivot) && (j > left));
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

		// �� �κ��� �� �𸣰���
		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
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
		printf("���� �μ��� �߸� �־����ϴ�.\n");
		exit(1);
	}

	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("�Է� ������ �� �� �����ϴ�.\n");
	}

	if ((outfile = fopen(argv[2], "w")) == NULL) {
		printf("��� ������ �� �� �����ϴ�.\n");
	}

	while (fscanf(infile, "%ld %s %d %s", &(edb[i].eid), edb[i].name, &(edb[i].escore), edb[i].dname) != EOF) i++;

	// 1. id�� ������������ ���Ͽ� ����
	quick_sorta(edb, 0, i - 1);
	printf("\n\nSorted Data.... \n");

	for (j = 0; j < 1; j++)
		fprintf(outfile, "%ld\t%s\t%d\t%s\n", (edb[j].eid), edb[j].name, (edb[j].escore), edb[j].dname);

	// 2. dcode�� �о� �� �μ��� �ش��ϴ� ������� ����ϱ�
	printf("Sales Department : S110\n");
	printf("Reasearch Department: R250\n");
	printf("Management Department: M210\n");
	printf("\nEnter the Deprartment code: ");
	scanf("%s", dcode); // char Ÿ�� �迭 dcode

	for (j = 0; j < i; j++) {
		if (strcmp(dcode, edb[j].dname) == 0) 
			printf("%ld\t%s\t%d\n", (edb[j].eid), edb[j].name, edb[j].escore);
	}

	// 3. ���� ������ ū ������ ���� ����ϱ�
	printf("\n\nFrom the highest English score To the lowest....\n");

	quick_sortd(edb, 0, i - 1);
	for (j = 0; j < i; j++) 
		printf("%ld\t%s\t%d\t%s\n", (edb[j].eid), edb[j].name, (edb[j].escore), edb[j].dname);
}