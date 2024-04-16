#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10

main() {
	char cdata[NUM];
	int i, j;

	srand((unsigned int)time(NULL)); // seed 값 설정

	cdata[0] = 'a' + rand() % 26; // 0~25중 하나를 'a'에 더하여 랜덤 알파벳 생성
	for (i = 1; i < NUM; i++) {
		cdata[i] = 'a' + rand() % 26;
		for (j = 0; j < i; j++) { // 생성된 문자가 배열 내 이전 문자들과 중복되지 않도록 검사
			if (cdata[i] == cdata[j]) { // 생성된 문자가 이전 문자와 중복된다면,
				i = j; // 현재 인덱스를 중복되는 이전 요소의 인덱스로 갱신
				break;
			}
		}
	}

	for (i = 0; i < NUM; i++) {
		printf("'%c' ", cdata[i]);
	}
	printf("\n");
}