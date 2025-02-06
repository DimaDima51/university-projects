#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct queue_element {
    char data;
    struct queue_element *next;
};
struct queue_element *head = NULL;
struct queue_element *tail = NULL;

void add(char symb) {
    struct queue_element *p = (struct queue_element*)malloc(sizeof(struct queue_element));
    p -> data = symb;
    p -> next = NULL;
    if(head == NULL) {
        head = p;
        tail = p;
    } else {
        tail -> next = p;
        tail = p;
    }
}

void print_queue(void) {
    struct queue_element *p = head;
    if(head == NULL)
        printf("Очередь пуста\n");
    else do {
        printf("%c ", p -> data);
        p = p -> next;
    } while(p != NULL);
}

int main() {
    system("cls");
    setlocale(LC_ALL, "RUS");
    
    char str[100];
    printf("Введите строку: ");
    gets(str);
    
    printf("Обрабатываемая строка: %s\n", str);
    
    int has_brackets = 0;
    for (int i = 0; i < strlen(str); i++) {
        if(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}') {
            add(str[i]);
            has_brackets = 1;
        }
    }
    
    if(has_brackets) {
        printf("Содержимое очереди: ");
        print_queue();
    } else
		printf("В выражении отсутствуют скобки.\n");
    
    return 0;
}
