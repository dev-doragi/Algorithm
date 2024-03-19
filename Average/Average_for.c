#define _CRT_SECURE_NO_WARNINGS
#define STUDENTS 5
#include <stdio.h>

int main() {
	int sum = 0;
	int score;
	float avg;

	printf("Input students' score.. \n");

	for (int i = 0; i < STUDENTS; i++) {
		scanf("%d", &score);
		sum += score;
	}

	avg = sum / STUDENTS;

	printf("The sum of score is %d\n", sum);
	printf("The average score is %.1f\n", avg);

	//return 0; // main함수에 리턴 값이 없으면 생략 가능
}
