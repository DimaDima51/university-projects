#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(LC_ALL, "RUS");
  int n;
  char term;
  printf("������� ����������� ����� � ��������� [1; 9]: ");
  if ((scanf("%d%c", &n, &term) != 2) || (term != '\n'))
    printf("������! �������� ����� �� �������� �����!");
  else if (n <= 0 || n > 9)
    printf("������! �������� ����� ��� ��������� [1; 9]!");
  else {
    for (int i = 1; i <= n; i++) {  // ������� ����� �����
      for (int j = n - i; j > 0; j--) {  // ������� ������� ����� �����������
        printf(" ");
      }
      for (int k = 1; k <= i; k++) {  // ������� ���������
        printf("* ");
      }
      printf("\n");  // ��������� �� ��������� ������
    }
    for (int i = n - 1; i >= 0; i--) {  // ������ ����� �����
      for (int j = n - i; j > 0; j--) {  // ������� ������� ����� �����������
        printf(" ");
      }
      for (int k = 1; k <= i; k++) {  // ������� ���������
        printf("* ");
      }
      printf("\n");  // ��������� �� ��������� ������
    }
  }
}