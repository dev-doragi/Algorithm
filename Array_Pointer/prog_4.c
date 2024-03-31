#define _CRT_SECURE_NO_WARNINGS
#define DMAX 100
#include <stdio.h>

double find_avg(int scores[][2], int n);
int find_max(int scores[][2], int n);
int find_rank(int scores[][2], int n, int sid);

main() {
	int n;
	int scores[DMAX][2];
	printf("Input Students' number...");
	scanf("%d", &n);

	printf("Input sid and score: ");
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &scores[i][0], &scores[i][1]);
	}

	printf("%d명의 학생 성적의 평균은 %.2f\n", n, find_avg(scores, n));
	printf("%d명의 학생 성적중 최대값은 %d\n", n, find_max(scores, n));

	printf("Input student id to search..");
	int sid;
	scanf("%d", &sid);
	printf("학번이 %d인 학생은 %d등\n", sid, find_rank(scores, n, sid));
}

double find_avg(int scores[][2], int n)
{
	int i, sum = 0;
	for (i = 0; i < n; i++)
		sum += scores[i][1];
	return (double) sum / n;
}

int find_max(int scores[][2], int n)
{	
	int i, max = 0;
	for (i = 0; i < n; i++)
		if (max < scores[i][1]) max = scores[i][1];
	return max;
}

int find_rank(int scores[][2], int n, int sid)
{
	int i, jumsu, rank = 1;
	for (i = 0; i < n; i++) {
		if (sid = scores[i][0]) {
			jumsu = scores[i][1];
			break;
		}
	}
	for (i = 0; i < n; i++)
		if (jumsu < scores[i][1]) rank++;
	return rank;
}
