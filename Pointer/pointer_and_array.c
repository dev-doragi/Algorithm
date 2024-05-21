//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 5
//
//// 소수점 아래의 값만 더해서 리턴하는 함수
//float trunc_sum(float* data); 
//
//main() {
//	float xarray[MAX], fsum = 0.0;
//	int i;
//	printf("Enter 10 reals: ");
//
//	for (i = 0; i < MAX; i++) {
//		scanf("%f", xarray + i);
//		fsum += *(xarray + i);
//	}
//	
//	printf("sum = %.2f\n", fsum);
//	printf("Truncation Value = %.2f\n", trunc_sum(xarray));
//}
//
//float trunc_sum(float data[]) {
//	float sum = 0.0;
//	int i, ivalue;
//
//	for (i = 0; i < MAX; i++) {
//		//ivalue = data[i]; // 실수 자료를 정수형으로 저장
//		//sum += (data[i] - ivalue); // 소수점 아래의 값만 더하기
//		ivalue = *(data + i);
//		sum += *(data + i) - ivalue;
//	}
//
//	return sum;
//}