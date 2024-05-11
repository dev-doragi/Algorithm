 동물 연결리스트 예제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct fnode* fpointer;
// 동물의 이름과 수를 저장할 구조체 fnode
struct fnode {
	char animal[10]; // 동물 이름
	int item; // 동물 수
	fpointer next;
};

void main() {
	fpointer head = NULL, ptr, another, before = NULL;
	int k, how_many = 0;


	head = (fpointer)malloc(sizeof(struct fnode)); // 첫번째 노드 생성
	strcpy(head->animal, "dog");
	head->item = 10;
	head->next = NULL;

	// head 노드에 추가할 4개의 노드 반복문
	for (k = 0; k < 4; k++) {
		another = (fpointer)malloc(sizeof(struct fnode));
		printf("Enter the sort of animal and its number.. ");
		// 새로 추가할 another구조체에서 이름과 수 입력
		scanf("%s %d", (another->animal), &(another->item)); 
		ptr = head;
		while (ptr != NULL) {
			before = ptr;
			ptr = ptr->next;
		}
		before->next = another;
		another->next = NULL;
	} 
	printf("========================================\n");

	ptr = head;
	// 구조체 포인터 처음부터 끝까지 item의 수와 값 출력하기
	while (ptr != NULL) {
		printf("%s: %d\n", ptr->animal, ptr->item);
		how_many += ptr->item;
		ptr = ptr->next;
	}
	printf("Total number of items: %d\n", how_many);
}
