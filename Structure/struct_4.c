#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ����ü�� ���� ����!
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
	ptr = make_node(); // ��ũ ��� ���� �� ptr�� ù��° ����� �ּ� ����
	print_list(ptr);
	printf("\n");
	print_list_while(ptr);
	printf("list���� data ��: %d\n", nodesum(ptr));
	printf("list���� node ��: %d\n", nodenumber(ptr));
}

list_pointer make_node() {
	list_pointer first, second, third;
	first = (list_pointer)malloc(sizeof(struct list_node));
	second = (list_pointer)malloc(sizeof(struct list_node));
	third = (list_pointer)malloc(sizeof(struct list_node));

	// first�� ������ second�ε�, second�� ���� ������ �ȵ��ֱ� ������
	third->link = NULL; // ��ũ�� �ڿ������� �����ϴ°� ����. 
	second->link = third;
	first->link = second;
	
	first->data = 100;
	second->data = 200;
	third->data = 300;
	return first;
}

// ptr�� ����Ű�� ������ �����Ͽ�, ptr->link�� ���� ���� ���� �̵��ϸ鼭 �ݺ�
// for ������ ���ǽ��� ptr�� NULL�� �ƴ� ����(ptr�� ��ȿ�� ��带 ����Ű�� ����) �ݺ�
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