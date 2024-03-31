//#define _CRT_SECURE_NO_WARNINGS
//#define DNUM 100
//#include <stdio.h>
//
//int pcount(int data[], int n);
//double avg(int data[], int n);
//int large(int data[], int n);
//int small(int data[], int n);
//
//main() {
//	int data[DNUM], k, n;
//	printf("처리할 데이터의 수: ");
//	scanf("%d", &n);
//	printf("%d개의 정수를 입력하세요.", n);
//	for (k = 0; k < n; k++) {
//		scanf("%d", &data[k]);
//	}
//	printf("양의 정수 개수는 %d\n", pcount(data, n));
//	printf("데이터의 평균 %.2f\n", avg(data, n));
//	printf("최대값 %d\n", large(data, n));
//	printf("최소값 %d\n", small(data, n));
//}
//
//int pcount(int data[], int n) {
//	int result = 0;
//	for (int j = 0; j < n; j++)
//		if (data[j] > 0) result++;
//	return result;
//}
//
//double avg(int data[], int n) {
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//		sum += data[i];
//	return (double) sum / n; // 실수 연산은 항상 명심할 것!
//}
//
//int large(int data[], int n) {
//	int largest = 0;
//	for (int i = 0; i < n; i++)
//		if (data[i] > largest) largest = data[i];
//	return largest;
//}
//
//int small(int data[], int n) {
//	int smallest = data[0];
//	for (int i = 1; i < n; i++)
//		if (data[i] < smallest) smallest = data[i];
//	return smallest;
//}