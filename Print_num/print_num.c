#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

main() {
	int r = 0;
	int num;

	printf("Input number... ");
	scanf("%d", &num);
	
	while (num > 0) {
		r = num % 10;
		printf("%d ", r);
		num = num / 10;
	}
}
