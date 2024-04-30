#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
	int n, data;
	int mult = 1;
	int flag = 1;
	int count = 0;

	printf("Input loop number... ");
	scanf("%d", &n);

	while (count < n) {
		scanf("%d", &data);
		if (data != 0) {
			mult = mult * data;
			flag = 0;
		}
		count++;
	}

	if (flag == 1) mult = 0;

	printf("Result: %d\n", mult);
}
