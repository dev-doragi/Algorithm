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
//	printf("ó���� �������� ��: ");
//	scanf("%d", &n);
//	printf("%d���� ������ �Է��ϼ���.", n);
//	for (k = 0; k < n; k++) {
//		scanf("%d", &data[k]);
//	}
//	printf("���� ���� ������ %d\n", pcount(data, n));
//	printf("�������� ��� %.2f\n", avg(data, n));
//	printf("�ִ밪 %d\n", large(data, n));
//	printf("�ּҰ� %d\n", small(data, n));
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
//	return (double) sum / n; // �Ǽ� ������ �׻� ����� ��!
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