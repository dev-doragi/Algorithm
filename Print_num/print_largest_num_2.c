#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
	int max = 0, size = 0;
	int num;

	printf("Input number.. ");
	scanf("%d", &num);

	while (num > 0) {
		if (num > max) max = num;
		size++;
		printf("Input number.. ");
		scanf("%d", &num);
	}

	printf("The size of number is: %d\n", size);
	if (size == 0) printf("No data!!\n");
	else printf("The maximum number is: %d\n", max);
}