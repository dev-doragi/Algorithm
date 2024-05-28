//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int add_product(int* a, int b);
//
//main() {
//	int x = 10, y = 20, z;
//	z = add_product(&x, y);
//	// 참조를 통해 x값은 바뀌었지만, y값은 값 복사를 통해 인자를 전달했으므로 값이 바뀌지 않았다.
//	printf("x = %d :: y = %d :: z = %d\n", x, y, z);
//}
//
//int add_product(int* a, int b) {
//	int temp = b;
//	b = *a + b;
//	*a = *a * temp;
//	return b;
//}