//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define NUM_VOWELS 5 // ���� 5��
//#define NUM_CONSONANTS 21 // ���� 21��
//
//char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u' };
//char consonants[NUM_CONSONANTS] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
//                                    'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
//
//// �Լ� ����
//char getRandomConsonant(); // ���� ���� ��ȯ
//char getRandomVowel(); // ���� ���� ��ȯ
//
//int main() {
//    srand((unsigned int)time(NULL)); // �õ� ����
//
//    int length = rand() % 5 + 4; // 4���� 8 ������ ���� �������� ����
//    int flag = 1;
//    printf("Generated Random Word: ");
//
//    // ù ��° ���ڸ� �빮�ڷ� ���
//    if (rand() % 10 > 3) { // 60% Ȯ���� ���� ����
//        printf("%c", getRandomConsonant() - 32);
//        flag = 0;
//    }
//    else {
//        printf("%c", getRandomVowel() - 32); // 40% Ȯ���� ���� ����
//        flag = 1;
//    }
//
//    for (int i = 1; i < length; i++) {
//        if (flag) {
//            if (rand() % 10 > 3) { // 60% Ȯ���� ���� ����
//                printf("%c", getRandomConsonant());
//                flag = 0;
//            }
//            else {
//                printf("%c", getRandomVowel()); // 40% Ȯ���� ���� ����
//                flag = 1;
//            }
//        }
//        else {
//            printf("%c", getRandomVowel()); // ���� ������ ������ ����
//            flag = 1;
//        }
//    }
//
//    printf("\n");
//
//    return 0;
//}
//
//// ���� ���� ��ȯ
//char getRandomConsonant() {
//    return consonants[rand() % NUM_CONSONANTS];
//}
//
//// ���� ���� ��ȯ
//char getRandomVowel() {
//    return vowels[rand() % NUM_VOWELS];
//}