#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 6

// �ĺ��� ������ �����ϱ� ���� ����ü ����
typedef struct {
    char name[50];
    char birthdate[11]; // YYYY/MM/DD ����
    char gender; // 'M' �Ǵ� 'F'
    char email[50];
    char nationality[30];
    float bmi;
    char main_skill[50];
    char sub_skill[50];
    char korean_level[20]; // �ѱ��� ���
    char mbti[5];
    char introduction[200]; // �ڱ�Ұ�
} Candidate;

int main() {
    Candidate candidates[CANDIDATE_COUNT];
    int i = 0;

    const char* korean_numbers[] = { "ù", "��", "��", "��", "�ټ�", "����" }; // �ѱ� ���� �迭

    printf("####################################\n");
    printf("     ����� �ĺ��� ������ �Է�\n");
    printf("####################################\n");

    while (i < CANDIDATE_COUNT) {
        printf("%s ��° �ĺ����� ������ �Է��մϴ�.\n", korean_numbers[i]);  // �������� �ѱ� �ĺ��� ��ȣ ���
        printf("---------------------------------\n");

        // ���� �Է�
        printf("1. ����: ");
        scanf_s("%s", candidates[i].name, sizeof(candidates[i].name));
        while (candidates[i].name[0] == '\0') {
            printf("������ �Է��� �ּ���: ");
            scanf_s("%s", candidates[i].name, sizeof(candidates[i].name));
        }

        // ���� �Է�
        printf("2. ����(YYYY/MM/DD ����): ");
        scanf_s("%s", candidates[i].birthdate, sizeof(candidates[i].birthdate));
        while (candidates[i].birthdate[0] == '\0') {
            printf("������ �Է��� �ּ���: ");
            scanf_s("%s", candidates[i].birthdate, sizeof(candidates[i].birthdate));
        }

        // ���� �Է�
        printf("3. ����(�����̸� F �Ǵ� �����̸� M): ");
        scanf_s(" %c", &candidates[i].gender, sizeof(candidates[i].gender));
        while (candidates[i].gender != 'M' && candidates[i].gender != 'F') {
            printf("������ F �Ǵ� M���� �Է��� �ּ���: ");
            scanf_s(" %c", &candidates[i].gender, sizeof(candidates[i].gender));
        }

        // ���� �ּ� �Է�
        printf("4. ���� �ּ�: ");
        scanf_s("%s", candidates[i].email, sizeof(candidates[i].email));
        while (candidates[i].email[0] == '\0') {
            printf("���� �ּҸ� �Է��� �ּ���: ");
            scanf_s("%s", candidates[i].email, sizeof(candidates[i].email));
        }

        // ���� �Է�
        printf("5. ����: ");
        scanf_s("%s", candidates[i].nationality, sizeof(candidates[i].nationality));
        while (candidates[i].nationality[0] == '\0') {
            printf("������ �Է��� �ּ���: ");
            scanf_s("%s", candidates[i].nationality, sizeof(candidates[i].nationality));
        }

        // BMI �Է�
        printf("6. BMI: ");
        scanf_s("%f", &candidates[i].bmi);
        while (candidates[i].bmi <= 0) {
            printf("BMI�� �ùٸ��� �Է��� �ּ���: ");
            scanf_s("%f", &candidates[i].bmi);
        }

        // �� ��ų �Է�
        printf("7. �� ��ų: ");
        scanf_s("%s", candidates[i].main_skill, sizeof(candidates[i].main_skill));
        while (candidates[i].main_skill[0] == '\0') {
            printf("�� ��ų�� �Է��� �ּ���: ");
            scanf_s("%s", candidates[i].main_skill, sizeof(candidates[i].main_skill));
        }

        // ���� ��ų �Է�
        printf("8. ���� ��ų: ");
        scanf_s("%s", candidates[i].sub_skill, sizeof(candidates[i].sub_skill));
        while (candidates[i].sub_skill[0] == '\0') {
            printf("���� ��ų�� �Է��� �ּ���: ");
            scanf_s("%s", candidates[i].sub_skill, sizeof(candidates[i].sub_skill));
        }

        // �ѱ��� ��� �Է�
        printf("9. �ѱ��� ���(TOPIK): ");
        scanf_s("%s", candidates[i].korean_level, sizeof(candidates[i].korean_level));
        while (candidates[i].korean_level[0] == '\0') {
            printf("�ѱ��� ����� �Է��� �ּ���: ");
            scanf_s("%s", candidates[i].korean_level, sizeof(candidates[i].korean_level));
        }

        // MBTI �Է�
        printf("10. MBTI: ");
        scanf_s("%s", candidates[i].mbti, sizeof(candidates[i].mbti));
        while (candidates[i].mbti[0] == '\0') {
            printf("MBTI�� �Է��� �ּ���: ");
            scanf_s("%s", candidates[i].mbti, sizeof(candidates[i].mbti));
        }

        // �ڱ�Ұ� �Է�
        printf("11. �Ұ�: ");
        getchar(); // �Է� ���� ����
        fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);
        while (candidates[i].introduction[0] == '\0') {
            printf("�ڱ�Ұ��� �Է��� �ּ���: ");
            fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);
        }

        i++;
        printf("=================================\n");
    }

    printf("####################################\n");
    printf("     ����� �ĺ��� ������ ��ȸ\n");
    printf("####################################\n");

    for (int j = 0; j < CANDIDATE_COUNT; j++) {
        printf("=================================================================================================================\n");
        printf("��   �� | ��   ��    | ���� | ��   ��                | ����    |  BMI  | �ֽ�ų    | ������ų    | TOPIK | MBTI |\n");
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
