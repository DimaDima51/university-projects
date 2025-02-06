#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int n; // ������ �������
	char term;
	printf("������� ������ �������: ");
	if ((scanf("%d%c", &n, &term) != 2) || (term != '\n')) { // �������� �� ���������� ���� ������ �����
		printf("������ ����� ������� �������!");
		return(-1);
	}
	
	if (n < 1) {
		printf("������� � �������� ��������� ������� �� ����������!");
		return(-1);
	}
	
	int array[n]; // ���������� ������� �������� n
	int max_abs = 0; // ������������ �� ������
	int min_val = 0; // ����������� �� ��������
	int sum = 0; // ����� ����� �������
	int count = 0; // ���������� ����� ������ �������� ���������������
	
	srand(time(NULL));
	
	printf("������: ");
	for (int i = 0; i < n; i++){
		array[i] = rand()%101 - 50;
		printf("%d ", array[i]); // ����� �������� �������
		
		if (abs(array[i]) > max_abs) // ���������� ������������� �� ������
			max_abs = abs(array[i]);
		
		if (array[i] < min_val) // ���������� ������������ �� ��������
			min_val = array[i];
		
		sum += array[i]; // ���������� ����� ��������� �������
	}
	
	float avg = ((float)sum/(float)n); // ������� ��������������
	
	for (int i = 0; i < n; i++) // ������� ����� ������ �������� ���������������
		if (array[i] > avg) count++;
			
	printf("\n������������ �� ������: %d\n", max_abs);
	printf("����������� �� ��������: %d\n", min_val);
	printf("������� ��������������: %.3f\n", avg);
	printf("���������� ����� ������ �������� ���������������: %d\n", count);
}