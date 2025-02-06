#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int floors = 10; // �����
	int rooms = 4; // ��������

	int house[floors][rooms];
	int residents = 0;
	
	srand(time(NULL));
	
	for (int i = floors - 1; i >= 0; i--){
		printf("���� %d: ", i + 1);
		for(int j = 0; j < rooms; j++){
			house[i][j] = rand()%7;
			printf("%d ", house[i][j]);
			residents += house[i][j];
		}
		printf("\n");
	}
	printf("����� �������: %d => ", residents);
	if (residents > 100) printf("�������� ��������!");
	else printf("�������� �� ��������!");
}