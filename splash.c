#include <stdio.h>
#include <stdlib.h>  

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void wait_three_seconds() {
    volatile long long i;  // �����Ϸ� ����ȭ�� �����ϱ� ���� volatile ���
    for (i = 0; i < 3000000000; i++) {
        
    }
}

void printStarsWithMessage(int i) 
{
    
    for (int j = 1; j <= i; j++) {
        printf("*");
    }
    switch (i)
    {
    case 1:
        printf("                         [���׶��׾� ver 0.1]                                     *****\n");
        break;
    case 2:
        printf("           Ǯ �� ���� ���� Ȳ�������� ��¦�̴� �༺�� ���鳻�� �� ���׶��׾�,     ****\n");
        break;
    case 3:
        printf("         ������� ���� ���ϴ� ������� ã�� �������� �ձ��� ���� ������ ���� ��,  ***\n");
        break;
    case 4:
        printf("           ���׶��׾ƿ� ���Ű� ȯ���մϴ�.                                        **\n");
        break;
    case 5:
        printf("                                                                                  *\n");
        break;

    }
}
int main() 
{
    char date[11];  
    char name[50];  

   
    printf("[���� ��¥�� \"yyyy-mm-dd\" �������� �Է��ϼ���]: ");
    scanf_s("%10s", date, (unsigned)_countof(date));

   
    printf("[����� �̸��� �Է��ϼ���]: ");
    scanf_s("%49s", name, (unsigned)_countof(name));

    
    printf("**�Է��� ���������� ó���Ǿ����ϴ�.**\n");

   
    wait_three_seconds();

    
    clear_screen();

    
      
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n");
   
    for (int i = 1; i <= 5; i++)
    {
       printStarsWithMessage(i);
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[�����]: %s                                         [���� �ð�]: %s\n", name, date);
    printf("=======================================================================================\n");
      
 }

    




