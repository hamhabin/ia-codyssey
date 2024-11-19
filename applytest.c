#include <stdio.h>
#include <math.h>

#define NUM_FIELDS 9
#define MIN_DAYS 30
#define MAX_DAYS 100

// �Ʒ� �о� ��� ����
enum { FITNESS, KNOWLEDGE, SELF_MANAGEMENT, TEAMWORK, KOREAN, VOCAL, DANCE, VISUAL, ACTING };
const char* fields[NUM_FIELDS] = {
    "ü��", "����", "�ڱ����", "����ũ", "�ѱ���", "����", "��", "���־�", "����"
};

// ���� ���� ����
int start_date = 0;
int test_dates[NUM_FIELDS] = { 0 };
int passed_tests[NUM_FIELDS] = { 0 }; // �� �оߺ� ���� ��� ���� ����

// ��¥ ���� Ȯ�� �Լ�
int validate_date(int date) {
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    if (year < 1900 || year > 2100) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;

    return 1;
}

// ��¥ ���� ��� �Լ� (YYYYMMDD ��������)
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

// ���� ���� ���� �ڰ� Ȯ�� �Լ�
int is_eligible_for_test(int field) {
    // �ڱ������ ����ũ�� ü�°� ���� ��� �Ŀ��� ����
    if ((field == SELF_MANAGEMENT || field == TEAMWORK) &&
        (!passed_tests[FITNESS] || !passed_tests[KNOWLEDGE])) {
        return 0;
    }
    // �ٸ� �оߴ� ���� ���� ���� ����
    return 1;
}

// ���� ���� ���� �Լ�
void apply_for_test(int field, int test_date) {
    int days_difference = calculate_days_difference(start_date, test_date);

    // ���� ���� ���� ���� ���� Ȯ��
    if (!is_eligible_for_test(field)) {
        printf("���� �Ұ�: ü�°� ���� �ܰ踦 ���� ����ؾ� �մϴ�.\n");
        return;
    }

    if (days_difference < MIN_DAYS) {
        printf("���� �Ұ�: �ּ� %d�� �Ŀ� ���� �����մϴ�.\n", MIN_DAYS);
    }
    else if (days_difference > MAX_DAYS) {
        printf("���� �Ұ�: �ִ� %d�� �̳��� �����ؾ� �մϴ�.\n", MAX_DAYS);
    }
    else {
        test_dates[field] = test_date;
        passed_tests[field] = 1;
        printf("%s �о� ������ %d ��¥�� ����Ǿ����ϴ�.\n", fields[field], test_date);
    }
}

int main() {
    // �Ʒ� ���� ��¥ �Է�
    printf("�Ʒ� ���� ��¥�� YYYYMMDD �������� �Է��ϼ���: ");
    scanf_s("%d", &start_date);

    if (!validate_date(start_date)) {
        printf("�߸��� ��¥ �����Դϴ�. ���α׷��� �����մϴ�.\n");
        return 1;
    }

    int field, test_date;

    while (1) {
        printf("\n���� ���� ���ø� ������ �о߸� �����ϼ���:\n");
        for (int i = 0; i < NUM_FIELDS; i++) {
            printf("%d. %s\n", i + 1, fields[i]);
        }
        printf("0. ����\n");
        printf("����: ");
        scanf_s("%d", &field);

        if (field == 0) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        if (field < 1 || field > NUM_FIELDS) {
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
            continue;
        }

        printf("���� ��¥�� YYYYMMDD �������� �Է��ϼ���: ");
        scanf_s("%d", &test_date);

        if (!validate_date(test_date)) {
            printf("�߸��� ��¥ �����Դϴ�. �ٽ� �õ��ϼ���.\n");
            continue;
        }

        apply_for_test(field - 1, test_date);
    }

    printf("\n--- ���� ���� ���� ��� ---\n");
    for (int i = 0; i < NUM_FIELDS; i++) {
        if (test_dates[i] != 0) {
            printf("%s: %d\n", fields[i], test_dates[i]);
        }
        else {
            printf("%s: ���� ����\n", fields[i]);
        }
    }

    return 0;
}
