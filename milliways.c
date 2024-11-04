#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 4

// Candidate structure
typedef struct {
    int id;
    char name[50];
    char birthdate[9];
    char gender[10];
    char email[50];
    char nationality[20];
    float bmi;
    char main_skill[20];
    char sub_skill[30];
    int topik;
    char mbti[5];
    int passed;  // 1 if passed, 0 if not
} Candidate;

// Additional data structure
typedef struct {
    int id;
    char name[50];
    char nickname[20];
    char birthdate[9];
    char gender[10];
    char email[50];
    char nationality[20];
    float bmi;
    float height; // meters
    float weight; // kg
    char blood_type[5];
    char allergy[20];
    char hobbies[50];
    char sns[50];
} MilliwaysMember;

// Candidate data
Candidate candidate_arr[NUM_CANDIDATES] = {
    {123456, "������", "20060415", "��", "jiyeon@outlook.com", "�ѱ�", 18.5, "��", "�۰�", 0, "ENFJ", 1},
    {654321, "Ethan Smith", "20050822", "��", "ethan@outlook.com", "�̱�", 21.2, "����", "�ۻ�", 2, "ISTP", 1},
    {112233, "Helena Silva", "20070310", "��", "helena@outlook.com", "�����", 20.8, "��", "�۰� �� �ۻ�", 3, "ENTJ", 1},
    {223344, "Liam Wilson", "20061108", "��", "liam@outlook.com", "ȣ��", 20.1, "��", "�۰� �� �ۻ�", 3, "ENTJ", 1}
};

// Additional member data (only for passed candidates)
MilliwaysMember milliways_arr[NUM_CANDIDATES] = {
    {123456, "������", "Ariel", "20060415", "��", "jiyeon@outlook.com", "�ѱ�", 18.5, 1.68, 0, "A", "����ǰ", "�� ����, �۰�", "Instagram - @Ariel_Jiyeon"},
    {654321, "Ethan Smith", "Simba", "20050822", "��", "ethan@outlook.com", "�̱�", 21.2, 1.78, 0, "O", "����", "�뷡 �۰�, �ｺ Ʈ���̴�", "Twitter - @Simba_Ethan"},
    {112233, "Helena Silva", "Belle", "20070310", "��", "helena@outlook.com", "�����", 20.8, 1.63, 0, "B", "����", "�뷡 �θ���, �׸� �׸���", "Instagram - @Belle_Helena"},
    {223344, "Liam Wilson", "Aladdin", "20061108", "��", "liam@outlook.com", "ȣ��", 20.1, 1.75, 0, "AB", "������", "���߱�, ���� ���ε��", "Instagram - @Aladdin_Liam"}
};

// Function to calculate weight using height and BMI
void calculate_weights() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (candidate_arr[i].passed) {
            milliways_arr[i].weight = milliways_arr[i].height * milliways_arr[i].height * candidate_arr[i].bmi;
        }
    }
}

// Function to print milliways_arr contents
void print_milliways_arr() {
    printf("=== Milliways Array ===\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (candidate_arr[i].passed) {
            printf("Member %d:\n", i + 1);
            printf("  ID: %d\n", milliways_arr[i].id);
            printf("  Name: %s\n", milliways_arr[i].name);
            printf("  Nickname: %s\n", milliways_arr[i].nickname);
            printf("  Birthdate: %s\n", milliways_arr[i].birthdate);
            printf("  Gender: %s\n", milliways_arr[i].gender);
            printf("  Email: %s\n", milliways_arr[i].email);
            printf("  Nationality: %s\n", milliways_arr[i].nationality);
            printf("  BMI: %.1f\n", milliways_arr[i].bmi);
            printf("  Height: %.2f m\n", milliways_arr[i].height);
            printf("  Weight: %.2f kg\n", milliways_arr[i].weight);
            printf("  Blood Type: %s\n", milliways_arr[i].blood_type);
            printf("  Allergy: %s\n", milliways_arr[i].allergy);
            printf("  Hobbies: %s\n", milliways_arr[i].hobbies);
            printf("  SNS: %s\n\n", milliways_arr[i].sns);
        }
    }
}

int main() {
    // Calculate weights based on height and BMI
    calculate_weights();

    // Print milliways_arr contents
    print_milliways_arr();

    return 0;
}
