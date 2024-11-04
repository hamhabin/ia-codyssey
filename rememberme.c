#include <stdio.h>

#define MEMORIAL_SIZE 2  // ���հ� �ĺ��� ��
#define MAX_MESSAGE 100  // �� �޽��� �ִ� ����
#define NAME_SIZE 50     // �ĺ��� �̸� �ִ� ����

// ���հ� �ĺ��� ���� ������ �ʱ�ȭ
const char memorial01_arr[] = "Suphanan Wong, suphanan@example.com";
const char memorial02_arr[] = "Karolina Nowak, karolina@example.com";

// �Ѹ������� �޽��� �迭 �ʱ�ȭ
char rollingpp01[MAX_MESSAGE];
char rollingpp02[MAX_MESSAGE];

// ���ڿ� �� �Լ� (string.h ��� ������ ���� ���� ����)
int compare_strings(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

void add_message(int candidate_index, const char* message) {
    // �� ���հ� �ĺ��ڿ��� ���� �޽����� rollingpp �迭�� ����
    if (candidate_index == 1) {
        snprintf(rollingpp01, MAX_MESSAGE, "{\"Suphanan Wong\": \"%s\"}", message);
    }
    else if (candidate_index == 2) {
        snprintf(rollingpp02, MAX_MESSAGE, "{\"Karolina Nowak\": \"%s\"}", message);
    }
}

void display_messages(int candidate_index) {
    // Ư�� ���հ� �ĺ����� �Ѹ������� �޽��� ���
    if (candidate_index == 1) {
        printf("Suphanan Wong: %s\n", rollingpp01);
    }
    else if (candidate_index == 2) {
        printf("Karolina Nowak: %s\n", rollingpp02);
    }
}

int main() {
    char candidate_name[NAME_SIZE];
    char message[MAX_MESSAGE];
    int candidate_index;

    printf("�հ��� �̸��� �޽����� �Է��ϼ��� (�����Ϸ��� 'exit' �Է�):\n");

    while (1) {
        printf("�հ��� �̸�: ");
        scanf_s("%49s", candidate_name, (unsigned)sizeof(candidate_name));

        // 'exit' �Է� �� ����
        if (compare_strings(candidate_name, "exit")) {
            break;
        }

        printf("�޽���: ");
        scanf_s(" %[^\n]", message, (unsigned)sizeof(message));

        // ���հ� �ĺ��ڿ� ���� �޽��� �߰�
        if (compare_strings(candidate_name, "Suphanan")) {
            candidate_index = 1;
        }
        else if (compare_strings(candidate_name, "Karolina")) {
            candidate_index = 2;
        }
        else {
            printf("���հ� �ĺ��� �̸��� Ȯ���ϼ���.\n");
            continue;
        }

        add_message(candidate_index, message);
    }

    // ���հ� �ĺ����� �޽��� ���
    printf("\n���հ� �ĺ��ڿ��� ���ϴ� ������� �޽���:\n");
    display_messages(1);
    display_messages(2);

    return 0;
}
