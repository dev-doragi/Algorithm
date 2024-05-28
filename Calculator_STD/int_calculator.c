//// ���� �м����
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//
//#define STAGE1 0 // operand1�� ���� �� ��������, �����ڸ� ������ STAGE2�� �̵�
//#define STAGE2 1 // ���� ��������, operand2�� �ް� ���� ������ ����
//#define STAGE3 2 // ��� ��� ��������, ������ ����� ����, ���ο� ������ �����Ұ��� ����
//
//	/* STAGE�� �� 3�ܰ�� ������ ����� ������ ������ ���� ���������� �Ѿ��.
//	   �ǿ����� �ΰ�, ������, ������ �׸����� ����, ���, ���� �������� */
//
//void int_calculator(void);
//int int_operation(char op, int operand1, int operand2);
//int get_int(int current_operand, char c);
//int is_operator(char c);
//int is_digit(char c);
//
//main() {
//	printf("���� ���α׷��� �����մϴ�. \n");
//	printf("�������� �ǿ����ڿ� ��Ģ������ �� �ϳ��� �Է��Ͻÿ�.\nPress x to get result and exit.\n");
//	int_calculator();
//	printf("\n��� �����մϴ�.\n");
//}
//
//int int_operation(char op, int operand1, int operand2) {
//	int result;
//	switch (op) {
//	case '+':
//		result = operand1 + operand2;
//		break;
//	case '-':
//		result = operand1 - operand2;
//		break;
//	case '*':
//		result = operand1 * operand2;
//		break;
//	case '/':
//		if (operand2 == 0) {
//			printf("\n0���� ���� �� �����ϴ�.\n");
//			result = operand1;
//		}
//		else
//			result = operand1 / operand2;
//		break;
//	case '^':
//		result = pow(operand1, operand2);
//		break;
//	}
//	return result;
//}
//
//void int_calculator(void) {
//	int operand1 = 0, operand2 = 0;
//	char op, c = '0';
//	int result;
//	int current_stage = STAGE1;
//
//	while (c != 'x') {
//		c = getchar();
//		if (current_stage == STAGE1) {
//			if (is_digit(c)) // �Է¹��� char c�� �����ΰ�?
//				operand1 = get_int(operand1, c);
//			else if (is_operator(c)) { // �Է¹��� char c�� �������ΰ�?
//				op = c;
//				current_stage = STAGE2; // ���� ���������� ����
//				operand2 = 0;
//			}
//		}
//		else if (current_stage == STAGE2) {
//			if (is_digit(c))
//				operand2 = get_int(operand2, c);
//			else if (c == '\n') {
//				result = int_operation(op, operand1, operand2);
//				printf("= %d", result);
//				current_stage = STAGE3;
//			}
//		}
//		else if (current_stage == STAGE3) {
//			if (c == '\n') {
//				operand1 = 0;
//				current_stage = STAGE1;
//			}
//			else if (is_operator(c)) {
//				op = c;
//				current_stage = STAGE2;
//				operand1 = result;
//				operand2 = 0;
//			}
//		}
//	}
//}
//
//int get_int(int current_operand, char c) {
//	int new_value;
//
//	new_value = c - '0'; // char ������ ������ ������ �ٲٱ� ���� 0�� ASCII���� ���� ���� ���� ������ �����Ѵ�.
//	current_operand *= 10; // �ڸ����� �÷��ֱ� ���� ���� �ǿ����ڿ� 10�� ���Ѵ�.
//	current_operand += new_value;
//	return current_operand;
//}
//
//int is_operator(char c) {
//	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
//		return 1;
//	else
//		return 0;
//}
//
//int is_digit(char c) {
//	if (c >= '0' && c <= '9')
//		return 1;
//	else
//		return 0;
//}
