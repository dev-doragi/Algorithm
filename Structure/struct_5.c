//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_CNUM 50
//
//typedef struct course {
//	char courseid[10]; // �а� id
//	char tname[20]; // ���� �̸�
//	unsigned snum; // ��� ��� ��
//	unsigned roomnum; // ���ǽ� ��ȣ
//} cinform;
//
//main(int argc, char* argv[])
//{
//	int i = 0, dnum; char sprof[20]; 
//	unsigned sroomnum; 
//	cinform cdb[MAX_CNUM]; 
//	FILE* coursedb;
//
//	if ((coursedb = fopen(argv[1], "r")) == NULL) {
//		printf("������ ������ �� �� �����ϴ� \n");
//		exit(1);
//	} 
//	
//	while (fscanf(coursedb, "%s %s %u %u", cdb[i].courseid, cdb[i].tname, &(cdb[i].snum), &(cdb[i].roomnum)) != EOF) 
//		i++; 
//
//	dnum = i; // ���� ������ dnum�� ����
//
//	printf("�����ο��� 40�� �̻��� ���� �ڵ� ��ȣ�� ����Ͻÿ�.\n"); 
//	for (i = 0; i < dnum; i++) 
//		if (cdb[i].snum >= 40) printf("%s\n", cdb[i].courseid);
//
//	printf("�˻��ϰ��� �ϴ� �����̸� �Է� : ");
//	scanf("%s", sprof); 
//	printf("%s ������ �����ϴ� �����ڵ�� ���ǽ� ��ȣ�� ����Ͻÿ�.\n", sprof); 
//
//	for (i = 0; i < dnum; i++) 
//		if (!strcmp(cdb[i].tname, sprof)) 
//			printf("%s\t%u\n", cdb[i].courseid, cdb[i].roomnum);
//
//	printf("�˻��ϰ��� �ϴ� ���ǽ� ��ȣ �Է� : ");
//	scanf("%u", &sroomnum); 
//	printf("%u ���ǽǿ��� �����ϴ� �����ڵ�� ��米���� ����Ͻÿ�.\n", sroomnum); 
//
//	for (i = 0; i < dnum; i++) 
//		if (cdb[i].roomnum == sroomnum) 
//			printf("%s\t%s\n", cdb[i].courseid, cdb[i].tname);
//}