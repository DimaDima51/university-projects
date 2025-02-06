#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(LC_ALL, "RUS");
  int n;
  char term;
  printf("Введите натуральное число в диапазоне [1; 9]: ");
  if ((scanf("%d%c", &n, &term) != 2) || (term != '\n'))
    printf("Ошибка! Введённое число не явялется целым!");
  else if (n <= 0 || n > 9)
    printf("Ошибка! Введённое число вне диапазона [1; 9]!");
  else {
    for (int i = 1; i <= n; i++) {  // Верхняя часть ромба
      for (int j = n - i; j > 0; j--) {  // Выводим пробелы перед звездочками
        printf(" ");
      }
      for (int k = 1; k <= i; k++) {  // Выводим звездочки
        printf("* ");
      }
      printf("\n");  // Переходим на следующую строку
    }
    for (int i = n - 1; i >= 0; i--) {  // Нижняя часть ромба
      for (int j = n - i; j > 0; j--) {  // Выводим пробелы перед звездочками
        printf(" ");
      }
      for (int k = 1; k <= i; k++) {  // Выводим звездочки
        printf("* ");
      }
      printf("\n");  // Переходим на следующую строку
    }
  }
}