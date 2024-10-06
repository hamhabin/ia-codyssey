#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 6

// 후보자 정보를 저장하기 위한 구조체 정의
typedef struct {
    char name[50];
    char birthdate[11]; // YYYY/MM/DD 형식
    char gender; // 'M' 또는 'F'
    char email[50];
    char nationality[30];
    float bmi;
    char main_skill[50];
    char sub_skill[50];
    char korean_level[20]; // 한국어 등급
    char mbti[5];
    char introduction[200]; // 자기소개
} Candidate;

int main() {
    Candidate candidates[CANDIDATE_COUNT];
    int i = 0;

    const char* korean_numbers[] = { "첫", "두", "세", "네", "다섯", "여섯" }; // 한글 숫자 배열

    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");

    while (i < CANDIDATE_COUNT) {
        printf("%s 번째 후보자의 정보를 입력합니다.\n", korean_numbers[i]);  // 동적으로 한글 후보자 번호 출력
        printf("---------------------------------\n");

        // 성명 입력
        printf("1. 성명: ");
        scanf_s("%s", candidates[i].name, sizeof(candidates[i].name));
        while (candidates[i].name[0] == '\0') {
            printf("성명을 입력해 주세요: ");
            scanf_s("%s", candidates[i].name, sizeof(candidates[i].name));
        }

        // 생일 입력
        printf("2. 생일(YYYY/MM/DD 형식): ");
        scanf_s("%s", candidates[i].birthdate, sizeof(candidates[i].birthdate));
        while (candidates[i].birthdate[0] == '\0') {
            printf("생일을 입력해 주세요: ");
            scanf_s("%s", candidates[i].birthdate, sizeof(candidates[i].birthdate));
        }

        // 성별 입력
        printf("3. 성별(여성이면 F 또는 남성이면 M): ");
        scanf_s(" %c", &candidates[i].gender, sizeof(candidates[i].gender));
        while (candidates[i].gender != 'M' && candidates[i].gender != 'F') {
            printf("성별을 F 또는 M으로 입력해 주세요: ");
            scanf_s(" %c", &candidates[i].gender, sizeof(candidates[i].gender));
        }

        // 메일 주소 입력
        printf("4. 메일 주소: ");
        scanf_s("%s", candidates[i].email, sizeof(candidates[i].email));
        while (candidates[i].email[0] == '\0') {
            printf("메일 주소를 입력해 주세요: ");
            scanf_s("%s", candidates[i].email, sizeof(candidates[i].email));
        }

        // 국적 입력
        printf("5. 국적: ");
        scanf_s("%s", candidates[i].nationality, sizeof(candidates[i].nationality));
        while (candidates[i].nationality[0] == '\0') {
            printf("국적을 입력해 주세요: ");
            scanf_s("%s", candidates[i].nationality, sizeof(candidates[i].nationality));
        }

        // BMI 입력
        printf("6. BMI: ");
        scanf_s("%f", &candidates[i].bmi);
        while (candidates[i].bmi <= 0) {
            printf("BMI를 올바르게 입력해 주세요: ");
            scanf_s("%f", &candidates[i].bmi);
        }

        // 주 스킬 입력
        printf("7. 주 스킬: ");
        scanf_s("%s", candidates[i].main_skill, sizeof(candidates[i].main_skill));
        while (candidates[i].main_skill[0] == '\0') {
            printf("주 스킬을 입력해 주세요: ");
            scanf_s("%s", candidates[i].main_skill, sizeof(candidates[i].main_skill));
        }

        // 보조 스킬 입력
        printf("8. 보조 스킬: ");
        scanf_s("%s", candidates[i].sub_skill, sizeof(candidates[i].sub_skill));
        while (candidates[i].sub_skill[0] == '\0') {
            printf("보조 스킬을 입력해 주세요: ");
            scanf_s("%s", candidates[i].sub_skill, sizeof(candidates[i].sub_skill));
        }

        // 한국어 등급 입력
        printf("9. 한국어 등급(TOPIK): ");
        scanf_s("%s", candidates[i].korean_level, sizeof(candidates[i].korean_level));
        while (candidates[i].korean_level[0] == '\0') {
            printf("한국어 등급을 입력해 주세요: ");
            scanf_s("%s", candidates[i].korean_level, sizeof(candidates[i].korean_level));
        }

        // MBTI 입력
        printf("10. MBTI: ");
        scanf_s("%s", candidates[i].mbti, sizeof(candidates[i].mbti));
        while (candidates[i].mbti[0] == '\0') {
            printf("MBTI를 입력해 주세요: ");
            scanf_s("%s", candidates[i].mbti, sizeof(candidates[i].mbti));
        }

        // 자기소개 입력
        printf("11. 소개: ");
        getchar(); // 입력 버퍼 비우기
        fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);
        while (candidates[i].introduction[0] == '\0') {
            printf("자기소개를 입력해 주세요: ");
            fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);
        }

        i++;
        printf("=================================\n");
    }

    printf("####################################\n");
    printf("     오디션 후보자 데이터 조회\n");
    printf("####################################\n");

    for (int j = 0; j < CANDIDATE_COUNT; j++) {
        printf("=================================================================================================================\n");
        printf("성   명 | 생   일    | 성별 | 메   일                | 국적    |  BMI  | 주스킬    | 보조스킬    | TOPIK | MBTI |\n");
        printf("=================================================================================================================\n");
        printf("%-8s | %-10s | %-3c | %-20s | %-10s | %-5.1f | %-8s | %-10s | %-5s | %-4s |\n",
            candidates[j].name, candidates[j].birthdate, candidates[j].gender,
            candidates[j].email, candidates[j].nationality, candidates[j].bmi,
            candidates[j].main_skill, candidates[j].sub_skill,
            candidates[j].korean_level, candidates[j].mbti);
        printf("        ---------------------------------------------------------------------------------------------------------\n");
        printf("%s", candidates[j].introduction);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
    }

    return 0;
}
