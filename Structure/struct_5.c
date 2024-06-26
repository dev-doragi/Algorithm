#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CNUM 50

typedef struct course {
	char courseid[10]; // 학과 id
	char tname[20]; // 교수 이름
	unsigned snum; // 듣는 사람 수
	unsigned roomnum; // 강의실 번호
} cinform;

main(int argc, char* argv[])
{
	int i = 0, dnum; char sprof[20]; 
	unsigned sroomnum; 
	cinform cdb[MAX_CNUM]; 
	FILE* coursedb;

	if ((coursedb = fopen(argv[1], "r")) == NULL) {
		printf("데이터 파일을 열 수 없습니다 \n");
		exit(1);
	} 
	
	while (fscanf(coursedb, "%s %s %u %u", cdb[i].courseid, cdb[i].tname, &(cdb[i].snum), &(cdb[i].roomnum)) != EOF) 
		i++; 

	dnum = i; // 강의 개수를 dnum에 저장

	printf("수강인원이 40명 이상인 강좌 코드 번호를 출력합니다.\n"); 
	for (i = 0; i < dnum; i++) 
		if (cdb[i].snum >= 40) printf("%s\n", cdb[i].courseid);
	printf("\n");

	printf("검색하고자 하는 교수이름 입력 : ");
	scanf("%s", sprof); 
	printf("%s 교수가 강의하는 강좌코드와 강의실 번호를 출력합니다..\n", sprof); 

	for (i = 0; i < dnum; i++) 
		if (!strcmp(cdb[i].tname, sprof)) // strcmp는 두 값이 같을 경우 0 반환한다.
			printf("%s\t%u\n", cdb[i].courseid, cdb[i].roomnum);
	printf("\n");


	printf("검색하고자 하는 강의실 번호 입력 : ");
	scanf("%u", &sroomnum); 
	printf("%u 강의실에서 수업하는 강좌코드와 담당교수를 출력합니다.\n", sroomnum); 

	for (i = 0; i < dnum; i++) 
		if (cdb[i].roomnum == sroomnum) 
			printf("%s\t%s\n", cdb[i].courseid, cdb[i].tname);
}