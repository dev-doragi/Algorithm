#define _CRT_SECURE_NO_WARNINGS // 항상 맨 위에 위치할 것!
#include <stdio.h>

int main() {
	int largest;
	int n1, n2, n3;

	printf("Input three different numbers.. ");
	scanf("%d %d %d", &n1, &n2, &n3);

	if (n1 > n2) largest = n1;
	else if (n1 == n2) {
		printf("Same number is prohibited\n");
		return 0;
	}
	else largest = n2;

	if (n3 > largest) largest = n3;
	else if (n3 == largest) {
		printf("Same number is prohibited\n");
		return 0;
	}

	printf("The largest number is %d", largest);

	return 0;
}
