#include <stdio.h>

#define MEMORIAL_SIZE 2  // 불합격 후보자 수
#define MAX_MESSAGE 100  // 한 메시지 최대 길이
#define NAME_SIZE 50     // 후보자 이름 최대 길이

// 불합격 후보자 기초 데이터 초기화
const char memorial01_arr[] = "Suphanan Wong, suphanan@example.com";
const char memorial02_arr[] = "Karolina Nowak, karolina@example.com";

// 롤링페이퍼 메시지 배열 초기화
char rollingpp01[MAX_MESSAGE];
char rollingpp02[MAX_MESSAGE];

// 문자열 비교 함수 (string.h 사용 금지로 인해 직접 구현)
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
    // 각 불합격 후보자에게 전할 메시지를 rollingpp 배열에 저장
    if (candidate_index == 1) {
        snprintf(rollingpp01, MAX_MESSAGE, "{\"Suphanan Wong\": \"%s\"}", message);
    }
    else if (candidate_index == 2) {
        snprintf(rollingpp02, MAX_MESSAGE, "{\"Karolina Nowak\": \"%s\"}", message);
    }
}

void display_messages(int candidate_index) {
    // 특정 불합격 후보자의 롤링페이퍼 메시지 출력
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

    printf("합격자 이름과 메시지를 입력하세요 (종료하려면 'exit' 입력):\n");

    while (1) {
        printf("합격자 이름: ");
        scanf_s("%49s", candidate_name, (unsigned)sizeof(candidate_name));

        // 'exit' 입력 시 종료
        if (compare_strings(candidate_name, "exit")) {
            break;
        }

        printf("메시지: ");
        scanf_s(" %[^\n]", message, (unsigned)sizeof(message));

        // 불합격 후보자에 따라 메시지 추가
        if (compare_strings(candidate_name, "Suphanan")) {
            candidate_index = 1;
        }
        else if (compare_strings(candidate_name, "Karolina")) {
            candidate_index = 2;
        }
        else {
            printf("불합격 후보자 이름을 확인하세요.\n");
            continue;
        }

        add_message(candidate_index, message);
    }

    // 불합격 후보자의 메시지 출력
    printf("\n불합격 후보자에게 전하는 동료들의 메시지:\n");
    display_messages(1);
    display_messages(2);

    return 0;
}
