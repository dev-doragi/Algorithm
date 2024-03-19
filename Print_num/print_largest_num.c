#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, data, large;
	int count = 1;
	
	printf("Input loop number... ");
	scanf("%d", &n);

	printf("Input number... ");
	scanf("%d", &data);

	large = data;

	while (count < n) {
		printf("Input number... ");
		scanf("%d", &data);
		if (large < data) large = data;
		count++;
	}

	printf("The largest number is %d\n", large);

	return 0;
}