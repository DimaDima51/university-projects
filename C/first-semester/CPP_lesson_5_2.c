#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int floors = 10; // �����
	int rooms = 4; // ��������
	
	int house[floors][rooms];
	
	srand(time(NULL));
	
	for(int i = floors-1; i >= 0; i--){ // ����������� �������
		printf("���� %d: ", i+1);
		for(int j = 0; j < rooms; j++){
			house[i][j] = rand()%7;
			printf("��.%d - %d ", (i * rooms + j) + 1, house[i][j]);
		}
		printf("\n");
	}
	
	int sampim; // ����� "������"
	char term; // ������ ��� ������������ ����� ������ �����
	printf("������� ����� \"������\": ");
	if ((scanf("%d%c", &sampim, &term) != 2) || (term != '\n')) { // �������� �� ���������� ���� ������ �����
		printf("������ ����� \"�������\"!");
		return(-1);
	}
	if (sampim < 1) { // �������� �� ������������� ����� "������"
		printf("����� ����� \"�������\" ���� �� �����!");
		return(-1);
	}
		
	printf("��������-����������: "); // ����������� ������ �������-�����������
	for(int i = floors - 1; i >= 0; i--){
		for(int j = 0; j < rooms; j++){
			if (house[i][j] * sampim > 100)
				printf("%d ", (i * rooms + j) + 1);
		}
	}

	int searchRoom; // ����� ������� ��������
	printf("\n������� ����� ��������: ");
	if ((scanf("%d%c", &searchRoom, &term) != 2) || (term != '\n')) { // �������� �� ���������� ���� ������ �����
		printf("������ ����� ������!");
		return(-1);
	}
	if ((searchRoom > floors*rooms) ||(searchRoom < 1)) { // �������� �� ������������� �������� � ����
		printf("����� �������� � ���� �� ����������!");
		return(-1);
	}
	printf("������� � �������� �%d - %d", searchRoom, house[searchRoom/rooms][searchRoom % rooms - 1]);
}