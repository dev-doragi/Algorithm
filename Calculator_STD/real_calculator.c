// ���� �м����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define STAGE1 0 // operand1�� ���� �� ��������
#define STAGE2 1 // ���� ��������, operand2�� �ް� ���� ������ ����
#define STAGE3 2 // ��� ��� ��������, ������ ����� ����, ���ο� ������ �����Ұ��� ����

void real_calculator(void);
double real_operation(char op, double operand1, double operand2);
double get_real(double current_operand, char c, int status);
int is_operator(char c);
int is_digit(char c);

// status = 0 -> ���� ��Ʈ, status != 0 -> �Ǽ� ��Ʈ

void main()
{
	printf("���� ���α׷��� �����մϴ�. \n");
	printf("�Ǽ����� �ǿ����ڿ� ��Ģ������ �� �ϳ��� �Է��Ͻÿ�.\nPress x to get result and exit. \n");
	real_calculator();
	printf("\n��� �����մϴ�.\n");
}

void real_calculator(void) {
	double operand1 = 0, operand2 = 0, result;
	char op, c;
	int current_stage = STAGE1, status = 0;

	while ((c = getchar()) != 'x') {
		if (current_stage == STAGE1) {
			if (is_digit(c)) {
				operand1 = get_real(operand1, c, status);
				if (status != 0) status++; 
				// status�� 0�� ���� ���� ��Ʈ�̹Ƿ� status ���� �ø��� �ʴ´�.
				// status�� 0�� �ƴϸ� �Ǽ� ��Ʈ�̹Ƿ�, ���� �Է� ���� ������ status ���� �ϳ��� �ø���.
			}
			else if (is_operator(c)) {
				op = c;
				current_stage = STAGE2;
				status = 0;
				operand2 = 0;
			}
			else if (c == '.') status = 1; // �Ǽ� ��Ʈ�� �Ѿ�鼭 status ���� 1�� �ȴ�.
		} // STAGE1

		else if (current_stage == STAGE2) {
			if (is_digit(c)) {
				operand2 = get_real(operand2, c, status);
				if (status != 0) status++;
			}
			else if (c == '.') status = 1;
			else if (c == '\n') {
				result = real_operation(op, operand1, operand2);
				printf("= %.3f", result);
				current_stage = STAGE3;
				status = 0;
			}
		} // STAGE2

		else if (current_stage == STAGE3) {
			if (c == '\n') {
				operand1 = 0;
				current_stage = STAGE1;
			}
			else if (is_operator(c)) {
				op = c;
				current_stage = STAGE2;
				operand1 = result;
				operand2 = 0;
			}
		} // STAGE3
	} // while
}

double get_real(double current_operand, char c, int status) {
	int part1;
	double part2;

	if (status == 0) { // status���� 0�̸�, ������ ó���Ѵ�.
		part1 = c - '0';
		current_operand *= 10;
		current_operand += part1;
	}
	else { // status���� 0�� �ƴϸ�, �Ǽ��� ó���Ѵ�.
		part2 = c - '0';
		part2 = part2 * pow(10, -status); // status ���� �ö� ������ 10^-1 = 1/10, 10^-2 = 1/100 ... �� �ȴ�.
		current_operand += part2;
	}
	return current_operand;
}

double real_operation(char op, double operand1, double operand2) {
	double result;
	switch (op) {
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	case '/':
		if (operand2 == 0) {
			printf("\n0���� ���� �� �����ϴ�.\n");
			result = operand1;
		}
		else
			result = operand1 / operand2;
		break;
	case '^':
		result = pow(operand1, operand2);
		break;
	}
	return result;
}

int is_operator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return 1;
	else
		return 0;
}

int is_digit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}