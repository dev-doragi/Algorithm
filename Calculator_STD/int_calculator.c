//// 상태 분석기법
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//
//#define STAGE1 0 // operand1을 받을 때 스테이지, 연산자를 받으면 STAGE2로 이동
//#define STAGE2 1 // 연산 스테이지, operand2를 받고 실제 연산을 수행
//#define STAGE3 2 // 결과 출력 스테이지, 연산을 계속할 건지, 새로운 연산을 수행할건지 결정
//
//	/* STAGE를 총 3단계로 나누어 계산을 진행할 때마다 다음 스테이지로 넘어간다.
//	   피연산자 두개, 연산자, 연산을 그만둘지 여부, 결과, 현재 스테이지 */
//
//void int_calculator(void);
//int int_operation(char op, int operand1, int operand2);
//int get_int(int current_operand, char c);
//int is_operator(char c);
//int is_digit(char c);
//
//main() {
//	printf("계산기 프로그램을 시작합니다. \n");
//	printf("정수형의 피연산자와 사칙연산자 중 하나를 입력하시오.\nPress x to get result and exit.\n");
//	int_calculator();
//	printf("\n장비를 정지합니다.\n");
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
//			printf("\n0으로 나눌 수 없습니다.\n");
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
//			if (is_digit(c)) // 입력받은 char c가 숫자인가?
//				operand1 = get_int(operand1, c);
//			else if (is_operator(c)) { // 입력받은 char c가 연산자인가?
//				op = c;
//				current_stage = STAGE2; // 연산 스테이지로 변경
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
//	new_value = c - '0'; // char 형에서 정수형 값으로 바꾸기 위해 0의 ASCII값을 빼서 실제 정수 값으로 변경한다.
//	current_operand *= 10; // 자리수를 올려주기 위해 현재 피연산자에 10씩 곱한다.
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
