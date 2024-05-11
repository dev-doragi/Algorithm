// �迭�� ���� ������ �����ϴ� �ǽ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPR_SIZE 50
#define MAX_STACK_SIZE 30

char pexpr[MAX_EXPR_SIZE]; // ���������� �Է��� ����ǥ����� ����
int stack[MAX_STACK_SIZE]; // ����ǥ��� ������ ���� ���� ���� �迭
int top; // ������ �ֻ��� �ε����� ������ top

int cal(void); // �������� pexpr�� �����Ͽ� ������ �����ϴ� �Լ�
int delete_stack(); // ������ ���� ���� �����ϴ� �Լ�
void add_stack(int data); // ������ ä��� �Լ�
int is_operator(char c); // ������ �Ǻ� �Լ�

void main() {
	printf("Input the expression as a postfix notation: \n");
	//gets(pexpr);
	for (int i = 0; i < 3; i++) {
		scanf("%s", pexpr); // gets(pexpr) ����ǥ��� �Է�
		printf("Evaluation Value: %d\n", cal()); // cal()�Լ� ���� �� ����� ��� ���
	}
}

// ���� pop
int delete_stack() {
	int data;
	if (top == -1) { // top �ε����� -1�̶�� ���� ������ ����� ��
		printf("Stack is empty.\n");
		exit(1);
	}
	// ������ �ֻ��� ���� data�� ���� �� ����, ���� top--
	data = stack[top]; top--; return data;
	//return stack[top--];
}

// ���� add
void add_stack(int data) {
	if (top >= MAX_STACK_SIZE - 1) { // top �ε����� MAX-1�̸� ������ �� á�� ��
		printf("Stack is full.\n");
		exit(1);
	}
	// top 1 �ø���, �Էµ� data�� �ش� �ε����� ���ÿ� ����
	++top; stack[top] = data;
	//stack[++top} = data;
}

int is_operator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') return 1;
	else return 0;
}

// ���� ���� �Լ�
int cal(void) {
	char symbol; // ���ڿ��� ����� ���ڸ� �ϳ��� ���� symbol
	int op1, op2, n = 0;

	top = -1; // ������ ó�� ��ġ�� ����
	symbol = pexpr[n++]; // pexpr���� ���� �ϳ� �޾ƿ�

	while (symbol != '\0') { // Enter�� ������ ������,
		if (is_operator(symbol)) { // �������� ���
			op2 = delete_stack(); // �ǿ����� �ޱ�
			op1 = delete_stack();
			switch (symbol) {
			case '+': add_stack(op1 + op2);
				break;
			case '-': add_stack(op1 - op2);
				break;
			case '*': add_stack(op1 * op2);
				break;
			case '/': add_stack(op1 / op2);
				break;
			}
		}
		else
			add_stack(symbol - '0'); // ���� ���� ���� int������ ��ȯ �� add_stack
		symbol = pexpr[n++]; // ���� ���� �޾ƿ���
	}
	return delete_stack(); // ����� ��� return
}
