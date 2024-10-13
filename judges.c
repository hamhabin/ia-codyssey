#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 5  // �ɻ� Ǯ �ִ� �ο�
#define MAX_JSON_LEN 512  // �� �ɻ��� ������ �ִ� ����

// �ɻ��� �迭 ����
char judges_array[MAX_JUDGES][MAX_JSON_LEN];

// ���ڿ����� ������ ���� ���ڸ� �����ϴ� �Լ�
void remove_newline(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';  // ���� ���ڸ� null ���ڷ� ��ü
            break;
        }
        i++;
    }
}

// �ɻ��� ���� �Է� �Լ�
void input_judges(int total_judges) {
    int i;
    for (i = 0; i < total_judges; i++) {
        printf("*�ɻ��� %d: ", i + 1);
        fgets(judges_array[i], MAX_JSON_LEN, stdin);
        remove_newline(judges_array[i]);  // ���� ���� ����

        // �Է� ���� üũ
        if (judges_array[i][0] == '\0') {
            printf("�ɻ��� ������ �ùٸ��� �Է����ּ���!\n");
            i--;  // �ٽ� �Է� �ޱ�
        }
    }
}

// JSON ������ �ɻ��� �����͸� �Ľ��Ͽ� ����ϴ� �Լ�
void print_judges(int total_judges) {
    for (int i = 0; i < total_judges; i++) {
        printf("[�ɻ��� %d]\n", i + 1);

        // �������� , �����ڸ� ã�Ƽ� ������ �и� �� ���
        char* ptr = judges_array[i];
        while (*ptr != '\0') {
            if (*ptr == ',') {
                printf("\n");  // , �����ڸ� ������ �ٹٲ�
            }
            else {
                printf("%c", *ptr);  // ���ڸ� �״�� ���
            }
            ptr++;
        }
        printf("\n-----------------------------------\n");
    }
}

int main() {
    char project_name[100];
    int judge_count = 0, select_count = 0;
    char view_judges = 'N';

    // ������Ʈ �̸� �� �ɻ��� Ǯ �ο� �Է�
    printf("####################################\n");
    printf("#       �ɻ��� Ǯ ������ �Է�       #\n");
    printf("####################################\n");
    printf("> ���� ������Ʈ: ");
    fgets(project_name, sizeof(project_name), stdin);
    remove_newline(project_name);  // ���� ���� ����

    printf("> �ɻ� Ǯ �ο�: ");
    scanf_s("%d", &judge_count);
    printf("> ���� ��� ��: ");
    scanf_s("%d", &select_count);
    getchar();  // ���� ���ڸ� ���� ����

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d���� �ɻ��� ���� �Է��� �����մϴ�.\n", judge_count);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // �ɻ��� ���� �Է�
    input_judges(judge_count);

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("�ɻ��� Ǯ �Է��� �������ϴ�.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // �ɻ��� Ǯ Ȯ�� ���� ����
    printf("�ɻ��� Ǯ�� Ȯ���ұ��? (Y/N): ");
    scanf_s(" %c", &view_judges, 1);

    // Y �Է� �� �ɻ��� ���� ���
    if (view_judges == 'Y') {
        printf("####################################\n");
        printf("#       �ɻ��� Ǯ ������ ���       #\n");
        printf("####################################\n");
        print_judges(judge_count);
    }
    else {
        printf("���α׷��� �����մϴ�.\n");
    }

    return 0;
}
