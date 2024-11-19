#include <stdio.h>
#include <math.h>

#define NUM_FIELDS 9
#define MIN_DAYS 30
#define MAX_DAYS 100

// 훈련 분야 상수 정의
enum { FITNESS, KNOWLEDGE, SELF_MANAGEMENT, TEAMWORK, KOREAN, VOCAL, DANCE, VISUAL, ACTING };
const char* fields[NUM_FIELDS] = {
    "체력", "지식", "자기관리", "팀워크", "한국어", "보컬", "댄스", "비주얼", "연기"
};

// 전역 변수 선언
int start_date = 0;
int test_dates[NUM_FIELDS] = { 0 };
int passed_tests[NUM_FIELDS] = { 0 }; // 각 분야별 시험 통과 여부 저장

// 날짜 형식 확인 함수
int validate_date(int date) {
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    if (year < 1900 || year > 2100) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;

    return 1;
}

// 날짜 차이 계산 함수 (YYYYMMDD 포맷으로)
int calculate_days_difference(int start, int end) {
    int start_year = start / 10000;
    int start_month = (start / 100) % 100;
    int start_day = start % 100;

    int end_year = end / 10000;
    int end_month = (end / 100) % 100;
    int end_day = end % 100;

    int start_days = start_year * 365 + start_month * 30 + start_day;
    int end_days = end_year * 365 + end_month * 30 + end_day;

    return end_days - start_days;
}

// 인증 시험 응시 자격 확인 함수
int is_eligible_for_test(int field) {
    // 자기관리와 팀워크는 체력과 지식 통과 후에만 가능
    if ((field == SELF_MANAGEMENT || field == TEAMWORK) &&
        (!passed_tests[FITNESS] || !passed_tests[KNOWLEDGE])) {
        return 0;
    }
    // 다른 분야는 제한 없이 응시 가능
    return 1;
}

// 인증 시험 예약 함수
void apply_for_test(int field, int test_date) {
    int days_difference = calculate_days_difference(start_date, test_date);

    // 인증 시험 응시 가능 여부 확인
    if (!is_eligible_for_test(field)) {
        printf("응시 불가: 체력과 지식 단계를 먼저 통과해야 합니다.\n");
        return;
    }

    if (days_difference < MIN_DAYS) {
        printf("응시 불가: 최소 %d일 후에 응시 가능합니다.\n", MIN_DAYS);
    }
    else if (days_difference > MAX_DAYS) {
        printf("응시 불가: 최대 %d일 이내에 응시해야 합니다.\n", MAX_DAYS);
    }
    else {
        test_dates[field] = test_date;
        passed_tests[field] = 1;
        printf("%s 분야 시험이 %d 날짜로 예약되었습니다.\n", fields[field], test_date);
    }
}

int main() {
    // 훈련 시작 날짜 입력
    printf("훈련 시작 날짜를 YYYYMMDD 형식으로 입력하세요: ");
    scanf_s("%d", &start_date);

    if (!validate_date(start_date)) {
        printf("잘못된 날짜 형식입니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    int field, test_date;

    while (1) {
        printf("\n인증 시험 응시를 예약할 분야를 선택하세요:\n");
        for (int i = 0; i < NUM_FIELDS; i++) {
            printf("%d. %s\n", i + 1, fields[i]);
        }
        printf("0. 종료\n");
        printf("선택: ");
        scanf_s("%d", &field);

        if (field == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        if (field < 1 || field > NUM_FIELDS) {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            continue;
        }

        printf("응시 날짜를 YYYYMMDD 형식으로 입력하세요: ");
        scanf_s("%d", &test_date);

        if (!validate_date(test_date)) {
            printf("잘못된 날짜 형식입니다. 다시 시도하세요.\n");
            continue;
        }

        apply_for_test(field - 1, test_date);
    }

    printf("\n--- 인증 시험 예약 결과 ---\n");
    for (int i = 0; i < NUM_FIELDS; i++) {
        if (test_dates[i] != 0) {
            printf("%s: %d\n", fields[i], test_dates[i]);
        }
        else {
            printf("%s: 예약 없음\n", fields[i]);
        }
    }

    return 0;
}
