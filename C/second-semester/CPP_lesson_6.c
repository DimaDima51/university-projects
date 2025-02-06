#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

#define MAX 50

int top = 0; // Вершина стека
char stack[MAX]; // Массив для стека

void push(char ch) {
    if (top >= MAX) {
        printf("Стек переполнен!\n");
        return;
    }
    top++;
    stack[top] = ch;
}

char pop() {
    if (top == 0) {
        printf("Стек пустой!\n");
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

    printf("Введите строку: ");
    scanf("%s", str);

    printf("Обрабатываемая строка: %s\n", str);

    while ((i < strlen(str)) && (flag == -1)) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i]);
            printf("В стек помещен символ %c, позиция в строке %d, top = %d\n", str[i], i, top);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            printf("Из стека пытаемся извлечь символ %c, позиция в строке %d\n", str[i], i);
            if (top == 0) {
                flag = 2; // Несоответствие скобок: закрывающихся скобок больше
            } else {
                char openBracket = pop();
                if ((str[i] == ')' && openBracket != '(') ||
                    (str[i] == ']' && openBracket != '[') ||
                    (str[i] == '}' && openBracket != '{')) {
                    printf("Ошибка: Несоответствие скобок: открывающаяся скобка %c не соответствует закрывающейся %c, в позиции %d\n", openBracket, str[i], i);
                    flag = 3; // Несоответствие скобок по виду
                } else {
                    printf("Из стека извлечаем символ %c, top = %d\n", str[i], top);
                }
            }
        }
        i++;
    }

    if (flag == -1) {
        if (top == 0) {
            flag = 0; // Ошибок в количестве скобок не обнаружено
        } else {
            flag = 1; // Открывающихся скобок больше
        }
    }

    switch (flag) {
        case 0:
            printf("Ошибок в количестве скобок не обнаружено\n");
            break;
        case 1:
            printf("Ошибка: Открывающихся скобок больше!\n");
            break;
        case 2:
            printf("Ошибка: Закрывающихся скобок больше!\n");
            break;
        case 3:
            printf("Ошибка: Несоответствие скобок по виду\n");
            break;
    }

    return 0;
}
