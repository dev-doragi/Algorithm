#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node* list_pointer; // struct list_node*를 list_pointer라고 부른다.
struct list_node {
	char data[5];
	list_pointer link;
};
list_pointer ptr = NULL; // 새로운 공백 리스트 ptr 생성

void print_list(list_pointer ptr);

main() {
	ptr = (list_pointer)malloc(sizeof(struct list_node));

	strcpy(ptr->data, "take");
	ptr->link = NULL;

	struct list_node one_node;
	strcpy(one_node.data, "sake");
	one_node.link = NULL;

	ptr->link = &one_node; // one_node의 주소를 ptr의 link에 할당

	print_list(ptr);
}

void print_list(list_pointer ptr) {
	printf("The list contains: ");
	for (; ptr; ptr = ptr->link) {
		printf("%s ", ptr->data);
	}
	printf("\n");
}