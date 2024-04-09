//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int gcd(int x, int y);
//
//// int 형의 argument c, char 포인터 형의 argument vector
//main(int argc, char* argv[])
//{
//	int a, b, result, answer, correct = 0, i = 0;
//	FILE* infile;
//	FILE* outfile;
//	if (argc != 3) {
//		printf("실행인수를 잘못 주었습니다..\n");
//		exit(1);
//	}
//
//	// argc[0] 일 때 -> 실행 exe 파일
//	if ((infile = fopen(argv[1], "r")) == NULL) {
//		printf("입력 파일을 열 수 없습니다. \n");
//		exit(1);
//	}
//
//	if ((outfile = fopen(argv[2], "w")) == NULL) {
//		printf("출력 파일을 만들 수 없습니다. \n");
//		exit(1);
//	}
//
//	while (fscanf(infile, "%d %d", &a, &b) != EOF) {
//		printf("%d: gcd(%d, %d) = ", i + 1, a, b);
//		scanf("%d", &answer);
//		result = gcd(a, b);
//		if (answer != result) {
//			printf("Answer: gcd(%d, %d) = %d \n", a, b, result);
//			fprintf(outfile, "%2d번 문제 오답!! gcd(%d, %d) = %d \n", i + 1, a, b, result); // 파일 저장
//		}
//		else {
//			printf("Correct...\n");
//			correct++;
//		}
//		i++;
//	}
//} 
//
//int gcd(int a, int b) {
//	if (b == 0) return a;
//	else
//	{
//		gcd(b, a % b);
//	}
//}