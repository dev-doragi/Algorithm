// 배열을 통해 스택을 구현하는 실습
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPR_SIZE 50
#define MAX_STACK_SIZE 30

char pexpr[MAX_EXPR_SIZE]; // 전역변수로 입력한 후위표기식을 저장
int stack[MAX_STACK_SIZE]; // 후위표기식 연산을 위해 쓰일 스택 배열
int top; // 스택의 최상위 인덱스를 저장할 top

int cal(void); // 전역변수 pexpr을 참조하여 연산을 진행하는 함수
int delete_stack(); // 스택을 비우며 값을 리턴하는 함수
void add_stack(int data); // 스택을 채우는 함수
int is_operator(char c); // 연산자 판별 함수

void main() {
	printf("Input the expression as a postfix notation: \n");
	//gets(pexpr);
	for (int i = 0; i < 3; i++) {
		scanf("%s", pexpr); // gets(pexpr) 후위표기식 입력
		printf("Evaluation Value: %d\n", cal()); // cal()함수 실행 후 연산된 결과 출력
	}
}

// 스택 pop
int delete_stack() {
	int data;
	if (top == -1) { // top 인덱스가 -1이라는 것은 스택이 비었을 때
		printf("Stack is empty.\n");
		exit(1);
	}
	// 스택의 최상위 값을 data에 저장 후 리턴, 스택 top--
	data = stack[top]; top--; return data;
	//return stack[top--];
}

// 스택 add
void add_stack(int data) {
	if (top >= MAX_STACK_SIZE - 1) { // top 인덱스가 MAX-1이면 스택이 꽉 찼을 때
		printf("Stack is full.\n");
		exit(1);
	}
	// top 1 올리고, 입력된 data를 해당 인덱스의 스택에 저장
	++top; stack[top] = data;
	//stack[++top} = data;
}

int is_operator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') return 1;
	else return 0;
}

// 스택 연산 함수
int cal(void) {
	char symbol; // 문자열에 저장된 문자를 하나씩 받을 symbol
	int op1, op2, n = 0;

	top = -1; // 스택을 처음 위치로 지정
	symbol = pexpr[n++]; // pexpr에서 값을 하나 받아옴

	while (symbol != '\0') { // Enter가 들어오기 전까지,
		if (is_operator(symbol)) { // 연산자일 경우
			op2 = delete_stack(); // 피연산자 받기
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
			add_stack(symbol - '0'); // 숫자 값을 실제 int형으로 변환 후 add_stack
		symbol = pexpr[n++]; // 다음 문자 받아오기
	}
	return delete_stack(); // 연산된 결과 return
}
