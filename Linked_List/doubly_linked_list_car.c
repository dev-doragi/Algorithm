#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> // malloc 함수를 사용하기 위해 추가

// 자동차 id와 등급을 가진 이중 연결 리스트 노드 정의
typedef struct node {
    struct node* left;   // 왼쪽 자식 노드를 가리키는 포인터
    unsigned carid;      // 자동차 ID
    char cgrade;         // 자동차 등급
    struct node* right;  // 오른쪽 자식 노드를 가리키는 포인터
} CARTYPE;

// 이진 탐색 트리를 만드는 함수 선언
int make_bst(CARTYPE* troot, unsigned id, char grade);
void nonpasscar(CARTYPE* troot);

int main() {
    CARTYPE* root = NULL;  // 이진 탐색 트리의 루트 초기화

    // 예제 데이터 삽입
    make_bst(&root, 1378, 'B');
    make_bst(&root, 2177, 'C');
    make_bst(&root, 1357, 'C');
    make_bst(&root, 1121, 'A');
    make_bst(&root, 1201, 'B');
    make_bst(&root, 2106, 'A');
    make_bst(&root, 1297, 'A');
    make_bst(&root, 1310, 'C');

    // A 등급이 아닌 자동차 ID 출력
    printf("A 등급이 아닌 자동차 ID:\n");
    nonpasscar(root);

    return 0;
}

// 이진 탐색 트리에 노드를 추가하는 함수
int make_bst(CARTYPE** root, unsigned id, char grade) {
    // tptr은 이진탐색트리의 루트, before는 부모 노드를 가리키는 포인터
    CARTYPE* tptr = root, * before = NULL;
    CARTYPE* node;  // 새로 추가할 노드를 가리키는 포인터

    // first는 해당 노드가 트리에 처음으로 추가되는 노드인지를 판단한다.
    int first = 0;

    // 만약 공백 트리일 경우, 해당 노드가 첫번째라는 것을 명시
    if (root == NULL) first = 1;

    // 트리를 탐색하면서, 추가할 id가 어느쪽에 속하는지 확인한다.
    while (tptr) {
        // 만약 id가 루트의 id보다 작으면,
        if (id < tptr->carid) {
            // 추가할 노드는 왼쪽으로 간다.
            before = tptr;
            tptr = tptr->left;
        }
        else if (id > tptr->carid) {
            // 추가할 노드는 오른쪽으로 간다.
            before = tptr;
            tptr = tptr->right;
        }
        // 추가할 값이 이미 있다면 추가할 필요가 없다.
        else // found
            return 0;
    }
    // while문이 끝나면, before의 값은 추가할 node의 부모 노드가 된다.

    // 노드를 추가할 위치를 찾았으면, 노드를 생성한다.
    node = (CARTYPE*)malloc(sizeof(CARTYPE));
    node->carid = id;
    node->cgrade = grade;
    node->left = node->right = NULL; // 서브 트리 값을 NULL로 초기화

    if (first == 0) { // 만약 추가할 노드가 첫번째 노드가 아니라면,
        if (id < before->carid) { // 추가할 노드의 ID가 부모 노드의 ID보다 작다면,
            before->left = node; // 왼쪽 자식으로 설정
        }
        else { // 추가할 노드의 ID가 부모 노드의 ID보다 크다면,
            before->right = node; // 오른쪽 자식으로 설정
        }
    }
    return 1; // 첫 번째 노드가 추가된 경우
}

// A 등급이 아닌 자동차 ID를 출력하는 함수
void nonpasscar(CARTYPE* root) {
    if (root) {
        // 중위 순회: 왼쪽 서브트리 방문, 현재 노드 방문, 오른쪽 서브트리 방문
        nonpasscar(root->left);
        if (root->cgrade != 'A') { // A 등급이 아닌 경우 ID 출력
            printf("%d\t", root->carid);
        }
        nonpasscar(root->right);
    }
}
