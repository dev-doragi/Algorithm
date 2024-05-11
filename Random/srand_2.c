#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 5

main() {
	float rdata[NUM], fsum = 0.0;
	int i, isum = 0, temp;

	srand((unsigned int)time(NULL)); // seed 값 설정
	for (i = 0; i < NUM; i++) {
		rdata[i] = rand() % 100 + rand() % 100 / 100.0; // 난수를 생성해 rdata[]에 저장 0~(99+0.99)
		printf("%.2f ", rdata[i]);
		if ((i + 1) % 7 == 0) {
			printf("\n");
		}
	}
	
	for (i = 0; i < NUM; i++) {
		temp = rdata[i]; // temp에 데이터를 넣음. temp는 정수형 변수이기 때문에 소수부분이 버려짐
		isum += temp; // 정수부분 더하기
		fsum += (rdata[i] - temp); // 원래의 데이터에서 정수부분을 뺀 값을 fsum에 더해줌
	}

	printf("\n\n정수부분의 합: %3d\n", isum);
	printf("\n소수부분의 합: %.3f\n", fsum);

	system("pause");
}