#define _CRT_SECURE_NO_WARNINGS
#define NUM 100
#include <stdio.h>

main() {
	int i, scores[NUM][2], sid, jumsu, rank, n;

	printf("Enter n: ");
	scanf("%d", &n);
	printf("Input id and score: ");

	for (i = 0; i < n; i++)
		scanf("%d %d", &scores[i][0], &scores[i][1]);

	printf("Input student id to search: ");
	scanf("%d", &sid);

	for (i = 0; i < n; i++) {
		if (sid == scores[i][0]) {
			jumsu = scores[i][1];
			break;
		}
	}

	rank = 0;

	for (i = 0; i < n; i++)
		if (scores[i][1] > jumsu) rank++;

	printf("%d ���� ����: %d\n", sid, jumsu);
	printf("%d ���� ���: %d\n", sid, rank + 1);
}