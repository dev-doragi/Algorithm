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
<<<<<<< HEAD

	return 0;
=======
>>>>>>> 7955e132e72b2a59b9f6eaf314842b382e858c77
}
