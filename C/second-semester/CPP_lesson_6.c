#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

#define MAX 50

int top = 0; // ������� �����
char stack[MAX]; // ������ ��� �����

void push(char ch) {
    if (top >= MAX) {
        printf("���� ����������!\n");
        return;
    }
    top++;
    stack[top] = ch;
}

char pop() {
    if (top == 0) {
        printf("���� ������!\n");
        return '0';
    }
    char symb = stack[top];
    stack[top] = 0;
    top--;
    return symb;
}

int main(void) {
    setlocale(LC_ALL, "RUS");
    int i = 0;
    int flag = -1;
    char str[MAX];

    printf("������� ������: ");
    scanf("%s", str);

    printf("�������������� ������: %s\n", str);

    while ((i < strlen(str)) && (flag == -1)) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i]);
            printf("� ���� ������� ������ %c, ������� � ������ %d, top = %d\n", str[i], i, top);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            printf("�� ����� �������� ������� ������ %c, ������� � ������ %d\n", str[i], i);
            if (top == 0) {
                flag = 2; // �������������� ������: ������������� ������ ������
            } else {
                char openBracket = pop();
                if ((str[i] == ')' && openBracket != '(') ||
                    (str[i] == ']' && openBracket != '[') ||
                    (str[i] == '}' && openBracket != '{')) {
                    printf("������: �������������� ������: ������������� ������ %c �� ������������� ������������� %c, � ������� %d\n", openBracket, str[i], i);
                    flag = 3; // �������������� ������ �� ����
                } else {
                    printf("�� ����� ��������� ������ %c, top = %d\n", str[i], top);
                }
            }
        }
        i++;
    }

    if (flag == -1) {
        if (top == 0) {
            flag = 0; // ������ � ���������� ������ �� ����������
        } else {
            flag = 1; // ������������� ������ ������
        }
    }

    switch (flag) {
        case 0:
            printf("������ � ���������� ������ �� ����������\n");
            break;
        case 1:
            printf("������: ������������� ������ ������!\n");
            break;
        case 2:
            printf("������: ������������� ������ ������!\n");
            break;
        case 3:
            printf("������: �������������� ������ �� ����\n");
            break;
    }

    return 0;
}
