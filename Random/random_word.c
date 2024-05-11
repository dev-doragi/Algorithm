//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define NUM_VOWELS 5 // 모음 5개
//#define NUM_CONSONANTS 21 // 자음 21개
//
//char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u' };
//char consonants[NUM_CONSONANTS] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
//                                    'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
//
//// 함수 선언
//char getRandomConsonant(); // 랜덤 자음 반환
//char getRandomVowel(); // 랜덤 모음 반환
//
//int main() {
//    srand((unsigned int)time(NULL)); // 시드 설정
//
//    int length = rand() % 5 + 4; // 4에서 8 사이의 길이 무작위로 선택
//    int flag = 1;
//    printf("Generated Random Word: ");
//
//    // 첫 번째 글자를 대문자로 출력
//    if (rand() % 10 > 3) { // 60% 확률로 자음 생성
//        printf("%c", getRandomConsonant() - 32);
//        flag = 0;
//    }
//    else {
//        printf("%c", getRandomVowel() - 32); // 40% 확률로 모음 생성
//        flag = 1;
//    }
//
//    for (int i = 1; i < length; i++) {
//        if (flag) {
//            if (rand() % 10 > 3) { // 60% 확률로 자음 생성
//                printf("%c", getRandomConsonant());
//                flag = 0;
//            }
//            else {
//                printf("%c", getRandomVowel()); // 40% 확률로 모음 생성
//                flag = 1;
//            }
//        }
//        else {
//            printf("%c", getRandomVowel()); // 자음 다음엔 무조건 모음
//            flag = 1;
//        }
//    }
//
//    printf("\n");
//
//    return 0;
//}
//
//// 랜덤 자음 반환
//char getRandomConsonant() {
//    return consonants[rand() % NUM_CONSONANTS];
//}
//
//// 랜덤 모음 반환
//char getRandomVowel() {
//    return vowels[rand() % NUM_VOWELS];
//}