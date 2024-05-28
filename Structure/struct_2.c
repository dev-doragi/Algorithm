// �ڱ����� ����ü: ����ü�� ����μ� �ڱ� �ڽŰ� ���� Ÿ���� ��忡 ���� �ּҸ� ������ ����ü.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct simple_list* simple_pointer; // �ڱ� ���� ����ü simple_list Ÿ���� simple_pointer ������(�迭) ����
struct simple_list { // simple_list ����ü ����
	char state[3]; // �̸��� ������ char �迭 state
	int count; // �ڵ带 ������ count
	simple_pointer next; // ���� ����ü ����� �ּҸ� ���� next
};

simple_pointer state_list(); // NY, FL�� �����ϱ� ���� �Լ�
void append(simple_pointer ptr, simple_pointer inode); // ����ü �����Ϳ� ���ο� ����ü�� �����ϱ� ���� �Լ�
void print_list(simple_pointer ptr); // ���� ����ü �������� ������ ����ϴ� �Լ� 

void main() {
	simple_pointer ptr, inode;

	ptr = state_list();
	// inode�� ����ü simple_list�� ũ�⸸ŭ�� �޸𸮸� �Ҵ�޾� simple_pointer(simple_list ������)Ÿ������ ĳ�����Ͽ� ����Ѵ�.
	inode = (simple_pointer)malloc(sizeof(struct simple_list));

	strcpy(inode->state, "TX");
	inode->count = 7;
	append(ptr, inode);
	print_list(ptr);

	free(ptr);
}

simple_pointer state_list() {
	simple_pointer node1, node2; // node1�� node2�� ����

	node1 = (simple_pointer)malloc(sizeof(struct simple_list));
	node2 = (simple_pointer)malloc(sizeof(struct simple_list));

	strcpy(node1->state, "NY");
	node1->count = 5;
	node1->next = node2; // node1�� ���� �ּҷ� node2�� ����
	strcpy(node2->state, "FL");
	node2->count = 10;
	node2->next = NULL;

	return node1;
}

// ptr�� ������ ��尡 ����Ű�� ���� inode�� �߰��ϴ� �Լ�
// ptr�� next�� node2�̴�. ptr->next�� ������ ������ ��带 ����Ű�°��� �ƴϴ�.
void append(simple_pointer ptr, simple_pointer inode) { // ptr�� ���� ���� inode�� �߰��ϴ� �Լ�
	 simple_pointer before = NULL; // ����ü before ����, �ʱ�ȭ

	 // ���� ptr�� ������ ����̱� ������ ���� �ּҰ� NULL�� ����, �̸� inode�� ���� �ּҷ� �����ؾ��Ѵ�.
	while (ptr != NULL) { // ptr�� NULL�� ����Ű�� ���� ���� ��,
		before = ptr; // before�� ptr�� ������ ��带 ����Ų��.
		ptr = ptr->next; 
	}
	before->next = inode; // before�� next�� inode�� ����
	inode->next = NULL; // inode�� ������ ���
}

// ����ü ������ ��� �Լ�
void print_list(simple_pointer ptr) {
	printf("The singly linked list contains: \n");
	while (ptr != NULL) {
		printf("%s: %d\n", ptr->state, ptr->count);
		ptr = ptr->next;
	}
}