#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 6
#define SCORE_COUNT 5 // 음악 소양, 댄스, 보컬, 비주얼, 전달력

// 후보자 정보를 저장하기 위한 구조체 정의
typedef struct {
    char name[50];
    int id; // 고유 ID, 중복되지 않는 6자리 정수
} Candidate;

// 심사자 정보를 저장하는 구조체 정의
typedef struct {
    char judge_name[50];
    char specialty[20]; // 전문 분야
} Judge;

// 후보자 점수 시트를 저장하는 구조체 정의
typedef struct {
    int id; // 후보자 고유 ID
    int scores[SCORE_COUNT]; // 5개 점수
    int total_score; // 총점
} ScoringSheet;

void enter_scores(Candidate candidates[], ScoringSheet scoring_sheets[], int candidate_count, Judge judge) {
    printf("####################################\n");
    printf("#       오디션 심사 결과 입력       #\n");
    printf("####################################\n");
    printf("> 심사자 이름: %s\n", judge.judge_name);
    printf("> 전문 분야: %s\n", judge.specialty);
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < candidate_count; i++) {
        printf("후보자: %s\n", candidates[i].name);
        printf("%s: ", judge.specialty);

        int score;
        while (1) {
            scanf_s("%d", &score);
            if (score >= 10 && score <= 100) break;
            printf("잘못된 점수입니다. 다시 입력해 주세요 (10~100): ");
        }

        scoring_sheets[i].id = candidates[i].id;
        scoring_sheets[i].scores[0] = score;
        scoring_sheets[i].total_score = score; // 일단 전문 분야 점수로 총점 초기화
        printf("------------------------------------\n");
    }

    printf("입력을 모두 완료했습니다.\n입력하신 내용을 검토하세요!\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d\n", candidates[i].name, scoring_sheets[i].total_score);
    }

    char submit;
    printf("제출하시겠습니까? (Y/N): ");
    while (1) {
        scanf_s(" %c", &submit, 1);
        if (submit == 'Y' || submit == 'N') break;
        printf("잘못된 입력입니다. Y 또는 N을 입력하세요: ");
    }

    if (submit == 'Y') {
        printf("***최종 제출을 완료했습니다.***\n");
    }
    else {
        printf("처음으로 돌아갑니다...\n");
        enter_scores(candidates, scoring_sheets, candidate_count, judge); // 다시 입력 시작
    }
}

void select_finalists(ScoringSheet scoring_sheets[], Candidate candidates[], int candidate_count) {
    // 총점에 따라 후보자 정렬 (내림차순)
    for (int i = 0; i < candidate_count - 1; i++) {
        for (int j = i + 1; j < candidate_count; j++) {
            if (scoring_sheets[i].total_score < scoring_sheets[j].total_score) {
                // ScoringSheet 스왑
                ScoringSheet temp = scoring_sheets[i];
                scoring_sheets[i] = scoring_sheets[j];
                scoring_sheets[j] = temp;

                // Candidate 스왑 (순서 맞추기 위해)
                Candidate temp_candidate = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp_candidate;
            }
        }
    }

    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");
    printf("#######################################\n");
    printf("# 밀리웨이즈의 멤버가 된 걸축하합니다!  #\n");
    printf("#######################################\n");

    // 상위 4명 출력
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int main() {
    // 후보자 초기화 (이름과 고유 ID)
    Candidate candidates[CANDIDATE_COUNT] = {
        {"박지연", 123456},
        {"Ethan Smith", 654321},
        {"Helena Silva", 112233},
        {"Liam Wilson", 223344},
        {"김하린", 334455},
        {"Chloe Nguyen", 445566}
    };

    // 점수 시트 배열
    ScoringSheet scoring_sheets[CANDIDATE_COUNT] = { 0 };

    // 심사자 정보 입력
    Judge judge;
    printf("심사자 이름을 입력하세요: ");
    scanf_s("%s", judge.judge_name, (unsigned)_countof(judge.judge_name));
    printf("심사자 전문 분야를 입력하세요(예: 음악, 댄스 등): ");
    scanf_s("%s", judge.specialty, (unsigned)_countof(judge.specialty));

    // 점수 입력 및 검토
    enter_scores(candidates, scoring_sheets, CANDIDATE_COUNT, judge);

    // 최종 선발 멤버 선택
    select_finalists(scoring_sheets, candidates, CANDIDATE_COUNT);

    return 0;
}
