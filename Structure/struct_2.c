// 자기참조 구조체: 구조체의 멤버로서 자기 자신과 같은 타입의 노드에 대한 주소를 가지는 구조체.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct simple_list* simple_pointer; // 자기 참조 구조체 simple_list 타입의 simple_pointer 포인터(배열) 생성
struct simple_list { // simple_list 구조체 선언
	char state[3]; // 이름을 저장할 char 배열 state
	int count; // 코드를 저장할 count
	simple_pointer next; // 다음 구조체 멤버의 주소를 가질 next
};

simple_pointer state_list(); // NY, FL을 저장하기 위한 함수
void append(simple_pointer ptr, simple_pointer inode); // 구조체 포인터에 새로운 구조체를 저장하기 위한 함수
void print_list(simple_pointer ptr); // 현재 구조체 포인터의 내용을 출력하는 함수 

void main() {
	simple_pointer ptr, inode;

	ptr = state_list();
	// inode는 구조체 simple_list의 크기만큼의 메모리를 할당받아 simple_pointer(simple_list 포인터)타입으로 캐스팅하여 사용한다.
	inode = (simple_pointer)malloc(sizeof(struct simple_list));

	strcpy(inode->state, "TX");
	inode->count = 7;
	append(ptr, inode);
	print_list(ptr);

	free(ptr);
}

simple_pointer state_list() {
	simple_pointer node1, node2; // node1과 node2를 선언

	node1 = (simple_pointer)malloc(sizeof(struct simple_list));
	node2 = (simple_pointer)malloc(sizeof(struct simple_list));

	strcpy(node1->state, "NY");
	node1->count = 5;
	node1->next = node2; // node1의 다음 주소로 node2를 설정
	strcpy(node2->state, "FL");
	node2->count = 10;
	node2->next = NULL;

	return node1;
}

// ptr의 마지막 노드가 가리키는 곳에 inode를 추가하는 함수
// ptr의 next는 node2이다. ptr->next가 무조건 마지막 노드를 가리키는것이 아니다.
void append(simple_pointer ptr, simple_pointer inode) { // ptr의 다음 노드로 inode를 추가하는 함수
	 simple_pointer before = NULL; // 구조체 before 생성, 초기화

	 // 현재 ptr은 마지막 노드이기 때문에 다음 주소가 NULL인 상태, 이를 inode의 시작 주소로 변경해야한다.
	while (ptr != NULL) { // ptr이 NULL을 가리키고 있지 않을 때,
		before = ptr; // before은 ptr의 마지막 노드를 가리킨다.
		ptr = ptr->next; 
	}
	before->next = inode; // before의 next를 inode로 설정
	inode->next = NULL; // inode가 마지막 노드
}

// 구조체 포인터 출력 함수
void print_list(simple_pointer ptr) {
	printf("The singly linked list contains: \n");
	while (ptr != NULL) {
		printf("%s: %d\n", ptr->state, ptr->count);
		ptr = ptr->next;
	}
}