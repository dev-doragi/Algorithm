#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);

// int ���� argument c, char ������ ���� argument vector
main(int argc, char* argv[])
{
	int a, b, result, answer, correct = 0, i = 0;
	FILE* infile;
	FILE* outfile;
	if (argc != 3) {
		printf("�����μ��� �߸� �־����ϴ�..\n");
		exit(1);
	}

	// argc[0] �� �� -> ���� exe ����
	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("�Է� ������ �� �� �����ϴ�. \n");
		exit(1);
	}

	if ((outfile = fopen(argv[2], "w")) == NULL) {
		printf("��� ������ ���� �� �����ϴ�. \n");
		exit(1);
	}

	while (fscanf(infile, "%d %d", &a, &b) != EOF) {
		printf("%d: gcd(%d, %d) = ", i + 1, a, b);
		scanf("%d", &answer);
		result = gcd(a, b);
		if (answer != result) {
			printf("Answer: gcd(%d, %d) = %d \n", a, b, result);
			fprintf(outfile, "%2d�� ���� ����!! gcd(%d, %d) = %d \n", i + 1, a, b, result); // ���� ����
		}
		else {
			printf("Correct...\n");
			correct++;
		}
		i++;
	}
} 

int gcd(int a, int b) {
	if (b == 0) return a;
	else
	{
		gcd(b, a % b);
	}
}