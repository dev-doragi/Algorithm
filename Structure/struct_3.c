 ���� ���Ḯ��Ʈ ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct fnode* fpointer;
// ������ �̸��� ���� ������ ����ü fnode
struct fnode {
	char animal[10]; // ���� �̸�
	int item; // ���� ��
	fpointer next;
};

void main() {
	fpointer head = NULL, ptr, another, before = NULL;
	int k, how_many = 0;


	head = (fpointer)malloc(sizeof(struct fnode)); // ù��° ��� ����
	strcpy(head->animal, "dog");
	head->item = 10;
	head->next = NULL;

	// head ��忡 �߰��� 4���� ��� �ݺ���
	for (k = 0; k < 4; k++) {
		another = (fpointer)malloc(sizeof(struct fnode));
		printf("Enter the sort of animal and its number.. ");
		// ���� �߰��� another����ü���� �̸��� �� �Է�
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
	// ����ü ������ ó������ ������ item�� ���� �� ����ϱ�
	while (ptr != NULL) {
		printf("%s: %d\n", ptr->animal, ptr->item);
		how_many += ptr->item;
		ptr = ptr->next;
	}
	printf("Total number of items: %d\n", how_many);
}
