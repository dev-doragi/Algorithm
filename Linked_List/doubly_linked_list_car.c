#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> // malloc �Լ��� ����ϱ� ���� �߰�

// �ڵ��� id�� ����� ���� ���� ���� ����Ʈ ��� ����
typedef struct node {
    struct node* left;   // ���� �ڽ� ��带 ����Ű�� ������
    unsigned carid;      // �ڵ��� ID
    char cgrade;         // �ڵ��� ���
    struct node* right;  // ������ �ڽ� ��带 ����Ű�� ������
} CARTYPE;

// ���� Ž�� Ʈ���� ����� �Լ� ����
int make_bst(CARTYPE* troot, unsigned id, char grade);
void nonpasscar(CARTYPE* troot);

int main() {
    CARTYPE* root = NULL;  // ���� Ž�� Ʈ���� ��Ʈ �ʱ�ȭ

    // ���� ������ ����
    make_bst(&root, 1378, 'B');
    make_bst(&root, 2177, 'C');
    make_bst(&root, 1357, 'C');
    make_bst(&root, 1121, 'A');
    make_bst(&root, 1201, 'B');
    make_bst(&root, 2106, 'A');
    make_bst(&root, 1297, 'A');
    make_bst(&root, 1310, 'C');

    // A ����� �ƴ� �ڵ��� ID ���
    printf("A ����� �ƴ� �ڵ��� ID:\n");
    nonpasscar(root);

    return 0;
}

// ���� Ž�� Ʈ���� ��带 �߰��ϴ� �Լ�
int make_bst(CARTYPE** root, unsigned id, char grade) {
    // tptr�� ����Ž��Ʈ���� ��Ʈ, before�� �θ� ��带 ����Ű�� ������
    CARTYPE* tptr = root, * before = NULL;
    CARTYPE* node;  // ���� �߰��� ��带 ����Ű�� ������

    // first�� �ش� ��尡 Ʈ���� ó������ �߰��Ǵ� ��������� �Ǵ��Ѵ�.
    int first = 0;

    // ���� ���� Ʈ���� ���, �ش� ��尡 ù��°��� ���� ���
    if (root == NULL) first = 1;

    // Ʈ���� Ž���ϸ鼭, �߰��� id�� ����ʿ� ���ϴ��� Ȯ���Ѵ�.
    while (tptr) {
        // ���� id�� ��Ʈ�� id���� ������,
        if (id < tptr->carid) {
            // �߰��� ���� �������� ����.
            before = tptr;
            tptr = tptr->left;
        }
        else if (id > tptr->carid) {
            // �߰��� ���� ���������� ����.
            before = tptr;
            tptr = tptr->right;
        }
        // �߰��� ���� �̹� �ִٸ� �߰��� �ʿ䰡 ����.
        else // found
            return 0;
    }
    // while���� ������, before�� ���� �߰��� node�� �θ� ��尡 �ȴ�.

    // ��带 �߰��� ��ġ�� ã������, ��带 �����Ѵ�.
    node = (CARTYPE*)malloc(sizeof(CARTYPE));
    node->carid = id;
    node->cgrade = grade;
    node->left = node->right = NULL; // ���� Ʈ�� ���� NULL�� �ʱ�ȭ

    if (first == 0) { // ���� �߰��� ��尡 ù��° ��尡 �ƴ϶��,
        if (id < before->carid) { // �߰��� ����� ID�� �θ� ����� ID���� �۴ٸ�,
            before->left = node; // ���� �ڽ����� ����
        }
        else { // �߰��� ����� ID�� �θ� ����� ID���� ũ�ٸ�,
            before->right = node; // ������ �ڽ����� ����
        }
    }
    return 1; // ù ��° ��尡 �߰��� ���
}

// A ����� �ƴ� �ڵ��� ID�� ����ϴ� �Լ�
void nonpasscar(CARTYPE* root) {
    if (root) {
        // ���� ��ȸ: ���� ����Ʈ�� �湮, ���� ��� �湮, ������ ����Ʈ�� �湮
        nonpasscar(root->left);
        if (root->cgrade != 'A') { // A ����� �ƴ� ��� ID ���
            printf("%d\t", root->carid);
        }
        nonpasscar(root->right);
    }
}
