#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 5  // 심사 풀 최대 인원
#define MAX_JSON_LEN 512  // 각 심사자 정보의 최대 길이

// 심사자 배열 선언
char judges_array[MAX_JUDGES][MAX_JSON_LEN];

// 문자열에서 마지막 개행 문자를 제거하는 함수
void remove_newline(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';  // 개행 문자를 null 문자로 대체
            break;
        }
        i++;
    }
}

// 심사자 정보 입력 함수
void input_judges(int total_judges) {
    int i;
    for (i = 0; i < total_judges; i++) {
        printf("*심사자 %d: ", i + 1);
        fgets(judges_array[i], MAX_JSON_LEN, stdin);
        remove_newline(judges_array[i]);  // 개행 문자 제거

        // 입력 누락 체크
        if (judges_array[i][0] == '\0') {
            printf("심사자 정보를 올바르게 입력해주세요!\n");
            i--;  // 다시 입력 받기
        }
    }
}

// JSON 형식의 심사자 데이터를 파싱하여 출력하는 함수
void print_judges(int total_judges) {
    for (int i = 0; i < total_judges; i++) {
        printf("[심사자 %d]\n", i + 1);

        // 수동으로 , 구분자를 찾아서 데이터 분리 후 출력
        char* ptr = judges_array[i];
        while (*ptr != '\0') {
            if (*ptr == ',') {
                printf("\n");  // , 구분자를 만나면 줄바꿈
            }
            else {
                printf("%c", *ptr);  // 문자를 그대로 출력
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

    // 프로젝트 이름 및 심사자 풀 인원 입력
    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    fgets(project_name, sizeof(project_name), stdin);
    remove_newline(project_name);  // 개행 문자 제거

    printf("> 심사 풀 인원: ");
    scanf_s("%d", &judge_count);
    printf("> 선발 멤버 수: ");
    scanf_s("%d", &select_count);
    getchar();  // 개행 문자를 비우기 위해

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", judge_count);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 정보 입력
    input_judges(judge_count);

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 확인 여부 묻기
    printf("심사자 풀을 확인할까요? (Y/N): ");
    scanf_s(" %c", &view_judges, 1);

    // Y 입력 시 심사자 정보 출력
    if (view_judges == 'Y') {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");
        print_judges(judge_count);
    }
    else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
