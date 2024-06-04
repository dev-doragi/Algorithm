#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

typedef struct node {
	struct node* left;
	unsigned carid;
	char cgrade;
	struct node* right;
} CARTYPE;

int make_bst(CARTYPE* troot, unsigned id, char grade);
void nonpasscar(CARTYPE* troot);

main() {
	CARTYPE* root = NULL;

	// 예제 데이터 삽입
	make_bst(&root, 1378, 'B');
	make_bst(&root, 2177, 'C');
	make_bst(&root, 1357, 'C');
	make_bst(&root, 1121, 'A');
	make_bst(&root, 1201, 'B');
	make_bst(&root, 2106, 'A');
	make_bst(&root, 1297, 'A');
	make_bst(&root, 1310, 'C');

	printf("A 등급이 아닌 자동차 ID:\n");
	nonpasscar(root);

	return 0;
}

int make_bst(CARTYPE* root, unsigned id, char grade) {
	CARTYPE* tptr = root, *before = NULL;
	CARTYPE* node;
	
	int first = 0;

	if (root == NULL) first = 1;

	while (tptr) {
		if (id < tptr->carid) {
			before = tptr;
			tptr = tptr->left;

		}
		else if (id > tptr->carid) {
			before = tptr;
			tptr = tptr->right;
		}
		else // found
			return 0;
	}

	node = (CARTYPE *)malloc(sizeof(CARTYPE));
	node->carid = id;
	node->cgrade = grade;
	node->left = node->right = NULL;

	if (first == 0) {
		if (id < before->carid) {
			before->left = node;
		}
		else {
			before->right = node;
		}
		return 1;
	}
}

void nonpasscar(CARTYPE* root) {
	if (root) {
		// 중위 순회
		nonpasscar(root->left);
		if (root->cgrade != 'A') {
			printf("%d\t", root->carid);
		}
		nonpasscar(root->right);
	}
}