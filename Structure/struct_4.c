#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 구조체를 먼저 선언!
typedef struct list_node* list_pointer;
struct list_node {
	int data;
	list_pointer link;
};

void print_list(list_pointer ptr);
void print_list_while(list_pointer ptr);
list_pointer make_node();
int nodesum(list_pointer ptr);
int nodenumber(list_pointer ptr);

void main() {
	list_pointer ptr;
	ptr = make_node(); // 링크 노드 만든 후 ptr에 첫번째 노드의 주소 저장
	print_list(ptr);
	printf("\n");
	print_list_while(ptr);
	printf("list안의 data 합: %d\n", nodesum(ptr));
	printf("list안의 node 수: %d\n", nodenumber(ptr));
}

list_pointer make_node() {
	list_pointer first, second, third;
	first = (list_pointer)malloc(sizeof(struct list_node));
	second = (list_pointer)malloc(sizeof(struct list_node));
	third = (list_pointer)malloc(sizeof(struct list_node));

	// first의 다음은 second인데, second가 아직 지정이 안되있기 때문에
	third->link = NULL; // 링크는 뒤에서부터 지정하는게 좋다. 
	second->link = third;
	first->link = second;
	
	first->data = 100;
	second->data = 200;
	third->data = 300;
	return first;
}

// ptr이 가리키는 노드부터 시작하여, ptr->link를 통해 다음 노드로 이동하면서 반복
// for 루프의 조건식은 ptr이 NULL이 아닌 동안(ptr이 유효한 노드를 가리키는 동안) 반복
void print_list(list_pointer ptr) {
	printf("The list contains: ");
	for (; ptr; ptr = ptr->link)
		printf("%4d", ptr->data);
	printf("\n");
}

void print_list_while(list_pointer ptr) {
	printf("The list contains: ");
	while (ptr) {
		printf("%4d", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

int nodesum(list_pointer ptr) {
	int sum = 0;
	//for (; ptr; ptr = ptr->link)
	//	sum += ptr->data;
	while (ptr) {
		sum += ptr->data;
		ptr = ptr->link;
	}
	return sum;
}

int nodenumber(list_pointer ptr) {
	int count = 0;
	for (; ptr; ptr = ptr->link)
		count++;
	return count;
}