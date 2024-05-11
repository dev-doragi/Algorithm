#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i, num;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 10; i++) {
		num = rand() % 101;
		printf("%d\n", num);
	}
}