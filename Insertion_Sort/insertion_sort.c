#define _CRT_SECURE_NO_WARNINGS
#define INUM 100
#include <stdlib.h>
#include <stdio.h>

// �й�, �̸�, ������ ������ student ����ü ����
typedef struct student {
	long id;
	char name[20];
	double score;
} sdatatype;

// ���� ������ �̹� ���ĵǾ� �ִ� �����Ϳ� ��������� ������ �����͸� ������ ��ġ�� �����Ͽ� ������ �����ϴ� ������ �̿��Ѵ�.
void insert_sort(sdatatype a[], int n);
void insert_sort1(sdatatype a[], int n);
void insert_sort2(sdatatype a[], int n);

main(int argc, char* argv[]) {
	sdatatype s[50];
	FILE* infile, * outfile;
	int i = 0, j;
	char choice;

	if (argc != 3) {
		printf("���� �μ��� �߸� �־����ϴ�. \n");
		exit(1);
	}

	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("�Է� ������ �� �� �����ϴ�. \n");
		exit(1);
	}

	if ((outfile = fopen(argv[2], "w")) == NULL) {
		printf("��� ������ �� �� �����ϴ�. \n");
		exit(1);
	}

	// s[i].name�� s[i].name �迭�� ù��° �ּҸ� ��Ÿ���Ƿ� &�� ������ �ʴ´�.
	while (fscanf(infile, "%ld %s %lf", &(s[i].id), s[i].name, &(s[i].score)) != EOF) i++;

	printf("�й� ������ �����Ϸ��� 1�� \n");
	printf("���� ������ �����Ϸ��� 2�� �����Ͻÿ�:  ");

	scanf("%c", &choice);

	if (choice == '1') insert_sort(s, i);
	else if (choice == '2') insert_sort2(s, i);
	else {
		printf("���ù�ȣ�� �߸� �Է��Ͽ����ϴ�.");
		exit(1);
	}

	printf("���� ���\n");
	for (j = 0; j < i; j++) {
		printf("%ld\t%s%\t%.2f\n", (s[j].id), s[j].name, (s[j].score));
		fprintf(outfile, "%ld\t%s%\t%.2f\n", (s[j].id), s[j].name, (s[j].score));
	}

	printf("��� �����մϴ�.\n");
}

//void insert_sort(sdatatype a[], int n) {
//	int i, j;
//	sdatatype temp;
//
//	for (i = 1; i < n; i++) {
//		temp = a[i];
//		for (j = i - 1; j >= 0; j--) {
//			if (a[j].id > temp.id) a[j + 1] = a[j]; // �ش� ������ �����̾ j ���� �����ϱ� ������ �ùٸ��� �ʴ�.
//		}
//		a[j + 1] = temp;
//	}
//}

// �й��� ������������ ����
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

// �й��� ������������ ����
void insert_sort1(sdatatype a[], int n) {
	int i, j;
	sdatatype temp;

	for (i = 1; i < n; i++) { // ���������� ù��° ��Ҹ� �̹� ���ĵ� ���·� �����ϰ� �����Ѵ�.
		temp = a[i]; // ���� ��Ҹ� temp�� ����
		j = i - 1; // ���� ����� ���� �ε���
		while (a[j].id > temp.id && j >= 0) { // ���� ����� id ���� ���� id ������ ũ�� j���� ������ �ƴ� ��,
			a[j + 1] = a[j]; // ���� ����� ���� ��ĭ�� �ڷ� �б�
			j--;
		}
		// while�� ������ a[j].id�� temp.id���� ���� ���� �ȴ�.
		a[j + 1] = temp; // �� ĭ�� �� �а� ���� �ڸ��� temp ����
	}
}

// ������ ������������ ���� (���� ū ���� ����)
void insert_sort2(sdatatype a[], int n) {
	int i, j;
	sdatatype temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while (a[j].score < temp.score && j >= 0) { // ���� ����� score ���� ���� score ������ ũ��, j�� ������ �ƴ� ��,
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp; // �� ĭ�� �� �а� ���� �ڸ��� temp ����
	}
}