#define _CRT_SECURE_NO_WARNINGS // �׻� �� ���� ��ġ�� ��!
#include <stdio.h>

main() {
	int a, b;
	char op;

	printf("Input two numbers: ");
	scanf("%d %d", &a, &b);
	printf("Input an Operator: ");
	scanf(" %c",  &op);

	if (op == '+') {
		int c = a + b;
		printf("%d %c %d = %d\n", a, op, b, c);
	}

	else if (op == '-') {
		int c = a - b;
		printf("%d %c %d = %d\n", a, op, b, c);
	}

	else if (op == '*') {
		int c = a * b;
		printf("%d %c %d = %d\n", a, op, b, c);
	}

	else if (op == '/') {
		if (b == 0) {
			printf("0���� ���� �� �����ϴ�. ��� �����մϴ�.\n");
			return 0;
		}
		double c = (double)a / (double)b;
		printf("%d %c %d = �� %.4f\n", a, op, b, c);
	}
	else printf("�߸��� �������Դϴ�. ��� �����մϴ�.\n");
}
