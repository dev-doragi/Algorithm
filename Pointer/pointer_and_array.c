//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 5
//
//// �Ҽ��� �Ʒ��� ���� ���ؼ� �����ϴ� �Լ�
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
//		//ivalue = data[i]; // �Ǽ� �ڷḦ ���������� ����
//		//sum += (data[i] - ivalue); // �Ҽ��� �Ʒ��� ���� ���ϱ�
//		ivalue = *(data + i);
//		sum += *(data + i) - ivalue;
//	}
//
//	return sum;
//}