//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int add_product(int* a, int b);
//
//main() {
//	int x = 10, y = 20, z;
//	z = add_product(&x, y);
//	// ������ ���� x���� �ٲ������, y���� �� ���縦 ���� ���ڸ� ���������Ƿ� ���� �ٲ��� �ʾҴ�.
//	printf("x = %d :: y = %d :: z = %d\n", x, y, z);
//}
//
//int add_product(int* a, int b) {
//	int temp = b;
//	b = *a + b;
//	*a = *a * temp;
//	return b;
//}