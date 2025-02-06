#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 50 // Определяем максимальную длину строки

struct stack_element {
    char data;
    struct stack_element *next;
};

struct stack_element *top = NULL;

void push(char symb) {
    struct stack_element *p = (struct stack_element*)malloc(sizeof(struct stack_element));
    p -> next = top;
    p -> data = symb;
    top = p;
}

char pop() {
    if (top == NULL) {
        return '\0'; // Возвращаем нулевой символ, чтобы обозначить пустой стек
    }
    char symb = top -> data;
    struct stack_element *p = top;
    top = top -> next;
    free (p);
    return symb;
}

void print_stack(void){
    struct stack_element *p = top;
    if (top == NULL)
        printf("Стек пуст!\n");
    else {
        printf("Стек:\n");
        while (p != NULL) {
            printf("%c\n", p -> data);
            p = p -> next;
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "RUS");
    int i = 0;
    char str[MAX];

    printf("Введите строку: ");
    scanf("%s", str);
 
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
            printf("Рассматривается символ %c\n\n", str[i]);
            print_stack();
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            char curr = pop();
            printf("Рассматривается символ %c\n\n", str[i]);
            print_stack();
            if (curr == '\0' || (curr == '(' && str[i] != ')') || (curr == '{' && str[i] != '}') || (curr == '[' && str[i] != ']')) {
                printf("Ошибка в расстановке скобок на позиции %d\n", i);
                return 1;
            }
        }
    }
 
    if (top == NULL) {
        printf("Ошибок в количестве скобок не обнаружено\n");
    } else {
        printf("Ошибка в расстановке скобок. Не хватает закрывающей скобки\n");
    }
    return 0;   
}
