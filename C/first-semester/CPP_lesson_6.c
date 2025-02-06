#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int floors = 10; // �����
	int rooms = 4; // ��������
	
	int house[floors][rooms]; // ���
	int noise[floors][2]; // 0 - ����� �����; 1 - ���������� ����
	
	srand(time(NULL));
	
	for(int i = floors-1; i >= 0; i--){ // ����������� ����
		int temp = 0; // ����� ���� �� ������
		printf("���� %d: ", i + 1);
		for(int j = 0; j < rooms; j++){
			house[i][j] = rand()%7;
			printf("%d ", house[i][j]);
			temp += house[i][j]; // ��������� ��� �� ����� �����
		}
		noise[i][0] = i; // ���������� ����� �����
		noise[i][1] = temp; // ���������� ������� ���� �� �����
		printf("\n");
	}
		
	// ���������� ���������
	for (int i = 0; i < floors-1; i++) {
		for (int j = 0; j < floors-i-1; j++) {
			if (noise[j][1] < noise[j+1][1]) {
				// ����� ����������
				int tempFloor = noise[j][0];
				int tempNoise = noise[j][1];
				noise[j][0] = noise[j+1][0];
				noise[j][1] = noise[j+1][1];
				noise[j+1][0] = tempFloor;
				noise[j+1][1] = tempNoise;
			}
		}
	}
	
	printf("\n��� ����� ������ ������:\n\n");
	for (int i = 0; i < 3; i++) { // ������� ��� ���
		printf("%d ����� - ���� %d (%d ���. ��.): ", i + 1, noise[i][0] + 1, noise[i][1]);
		for(int k = floors-1; k >= 0; k--){
			for(int j = 0; j < rooms; j++){
				if (noise[i][0] == k && house[k][j] != 0)
				printf("��.%d (%d �.�.) ",  (k * rooms + j) + 1, house[k][j]);
			}
		}
		printf("\n");
	}
}