#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd_1(int a, int b);
int gcd_2(int a, int b);

main() {
	int result;
	int a, b, cond = 1;

	while (cond) {
		printf("최대공약수를 구할 두 수를 입력 하세요... ");
		scanf("%d %d", &a, &b); 
		result = gcd_1(a, b);
		printf("gcd(%d, %d) = %d \n\n", a, b, result);
		printf("계속하시겠습니까? (1/0) ");
		scanf("%d", &cond);
	}
}

int gcd_1(int a, int b) {
	if (b == 0) return a;
	else
	{
		gcd_1(b, a % b);
	}
}

int gcd_2(int a, int b)
{
	int tmp;
	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
