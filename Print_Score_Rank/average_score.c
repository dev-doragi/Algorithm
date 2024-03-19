#define _CRT_SECURE_NO_WARNINGS
#define DMAX 100
#include <stdio.h>

main() {
	int n, cnt = 0, sum = 0;
	double avg;
	int scores[DMAX];

	printf("Input the number of students.. ");
	scanf("%d", &n);

	printf("Input scores... ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &scores[i]);
	}

	for (int i = 0; i < n; i++) {
		sum += scores[i];
	}

	avg = (double) sum / n;

	for (int i = 0; i < n; i++) {
		if (scores[i] > avg) cnt++;
	}

	printf("The average of score is: %.2f\n", avg);
	printf("The number of Upper scores is: %d\n", cnt);
}