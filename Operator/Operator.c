#define _CRT_SECURE_NO_WARNINGS // 항상 맨 위에 위치할 것!
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
			printf("0으로 나눌 수 없습니다. 장비를 정지합니다.\n");
			return 0;
		}
		double c = (double)a / (double)b;
		printf("%d %c %d = 약 %.4f\n", a, op, b, c);
	}
	else printf("잘못된 연산자입니다. 장비를 정지합니다.\n");
}
