#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10

main() {
	char cdata[NUM];
	int i, j;

	srand((unsigned int)time(NULL)); // seed �� ����

	cdata[0] = 'a' + rand() % 26; // 0~25�� �ϳ��� 'a'�� ���Ͽ� ���� ���ĺ� ����
	for (i = 1; i < NUM; i++) {
		cdata[i] = 'a' + rand() % 26;
		for (j = 0; j < i; j++) { // ������ ���ڰ� �迭 �� ���� ���ڵ�� �ߺ����� �ʵ��� �˻�
			if (cdata[i] == cdata[j]) { // ������ ���ڰ� ���� ���ڿ� �ߺ��ȴٸ�,
				i = j; // ���� �ε����� �ߺ��Ǵ� ���� ����� �ε����� ����
				break;
			}
		}
	}

	for (i = 0; i < NUM; i++) {
		printf("'%c' ", cdata[i]);
	}
	printf("\n");
}