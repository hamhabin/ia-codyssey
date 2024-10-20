#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 6
#define SCORE_COUNT 5 // ���� �Ҿ�, ��, ����, ���־�, ���޷�

// �ĺ��� ������ �����ϱ� ���� ����ü ����
typedef struct {
    char name[50];
    int id; // ���� ID, �ߺ����� �ʴ� 6�ڸ� ����
} Candidate;

// �ɻ��� ������ �����ϴ� ����ü ����
typedef struct {
    char judge_name[50];
    char specialty[20]; // ���� �о�
} Judge;

// �ĺ��� ���� ��Ʈ�� �����ϴ� ����ü ����
typedef struct {
    int id; // �ĺ��� ���� ID
    int scores[SCORE_COUNT]; // 5�� ����
    int total_score; // ����
} ScoringSheet;

void enter_scores(Candidate candidates[], ScoringSheet scoring_sheets[], int candidate_count, Judge judge) {
    printf("####################################\n");
    printf("#       ����� �ɻ� ��� �Է�       #\n");
    printf("####################################\n");
    printf("> �ɻ��� �̸�: %s\n", judge.judge_name);
    printf("> ���� �о�: %s\n", judge.specialty);
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < candidate_count; i++) {
        printf("�ĺ���: %s\n", candidates[i].name);
        printf("%s: ", judge.specialty);

        int score;
        while (1) {
            scanf_s("%d", &score);
            if (score >= 10 && score <= 100) break;
            printf("�߸��� �����Դϴ�. �ٽ� �Է��� �ּ��� (10~100): ");
        }

        scoring_sheets[i].id = candidates[i].id;
        scoring_sheets[i].scores[0] = score;
        scoring_sheets[i].total_score = score; // �ϴ� ���� �о� ������ ���� �ʱ�ȭ
        printf("------------------------------------\n");
    }

    printf("�Է��� ��� �Ϸ��߽��ϴ�.\n�Է��Ͻ� ������ �����ϼ���!\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d\n", candidates[i].name, scoring_sheets[i].total_score);
    }

    char submit;
    printf("�����Ͻðڽ��ϱ�? (Y/N): ");
    while (1) {
        scanf_s(" %c", &submit, 1);
        if (submit == 'Y' || submit == 'N') break;
        printf("�߸��� �Է��Դϴ�. Y �Ǵ� N�� �Է��ϼ���: ");
    }

    if (submit == 'Y') {
        printf("***���� ������ �Ϸ��߽��ϴ�.***\n");
    }
    else {
        printf("ó������ ���ư��ϴ�...\n");
        enter_scores(candidates, scoring_sheets, candidate_count, judge); // �ٽ� �Է� ����
    }
}

void select_finalists(ScoringSheet scoring_sheets[], Candidate candidates[], int candidate_count) {
    // ������ ���� �ĺ��� ���� (��������)
    for (int i = 0; i < candidate_count - 1; i++) {
        for (int j = i + 1; j < candidate_count; j++) {
            if (scoring_sheets[i].total_score < scoring_sheets[j].total_score) {
                // ScoringSheet ����
                ScoringSheet temp = scoring_sheets[i];
                scoring_sheets[i] = scoring_sheets[j];
                scoring_sheets[j] = temp;

                // Candidate ���� (���� ���߱� ����)
                Candidate temp_candidate = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp_candidate;
            }
        }
    }

    printf("=======================================\n");
    printf("�ĺ� ���� ��� ���� �� ...\n");
    printf("=======================================\n");
    printf("#######################################\n");
    printf("# �и��������� ����� �� �������մϴ�!  #\n");
    printf("#######################################\n");

    // ���� 4�� ���
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int main() {
    // �ĺ��� �ʱ�ȭ (�̸��� ���� ID)
    Candidate candidates[CANDIDATE_COUNT] = {
        {"������", 123456},
        {"Ethan Smith", 654321},
        {"Helena Silva", 112233},
        {"Liam Wilson", 223344},
        {"���ϸ�", 334455},
        {"Chloe Nguyen", 445566}
    };

    // ���� ��Ʈ �迭
    ScoringSheet scoring_sheets[CANDIDATE_COUNT] = { 0 };

    // �ɻ��� ���� �Է�
    Judge judge;
    printf("�ɻ��� �̸��� �Է��ϼ���: ");
    scanf_s("%s", judge.judge_name, (unsigned)_countof(judge.judge_name));
    printf("�ɻ��� ���� �о߸� �Է��ϼ���(��: ����, �� ��): ");
    scanf_s("%s", judge.specialty, (unsigned)_countof(judge.specialty));

    // ���� �Է� �� ����
    enter_scores(candidates, scoring_sheets, CANDIDATE_COUNT, judge);

    // ���� ���� ��� ����
    select_finalists(scoring_sheets, candidates, CANDIDATE_COUNT);

    return 0;
}
