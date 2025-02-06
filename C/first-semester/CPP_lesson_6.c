#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int floors = 10; // Этажи
	int rooms = 4; // Квартиры
	
	int house[floors][rooms]; // Дом
	int noise[floors][2]; // 0 - номер этажа; 1 - количество шума
	
	srand(time(NULL));
	
	for(int i = floors-1; i >= 0; i--){ // Отображение дома
		int temp = 0; // Сумма шума на этажей
		printf("Этаж %d: ", i + 1);
		for(int j = 0; j < rooms; j++){
			house[i][j] = rand()%7;
			printf("%d ", house[i][j]);
			temp += house[i][j]; // Суммируем шум со всего этажа
		}
		noise[i][0] = i; // Записываем номер этажа
		noise[i][1] = temp; // Записываем уровень шума на этаже
		printf("\n");
	}
		
	// Сортировка пузырьком
	for (int i = 0; i < floors-1; i++) {
		for (int j = 0; j < floors-i-1; j++) {
			if (noise[j][1] < noise[j+1][1]) {
				// Обмен значениями
				int tempFloor = noise[j][0];
				int tempNoise = noise[j][1];
				noise[j][0] = noise[j+1][0];
				noise[j][1] = noise[j+1][1];
				noise[j+1][0] = tempFloor;
				noise[j+1][1] = tempNoise;
			}
		}
	}
	
	printf("\nТоп самых шумных этажей:\n\n");
	for (int i = 0; i < 3; i++) { // Выводим топ три
		printf("%d место - Этаж %d (%d шум. ед.): ", i + 1, noise[i][0] + 1, noise[i][1]);
		for(int k = floors-1; k >= 0; k--){
			for(int j = 0; j < rooms; j++){
				if (noise[i][0] == k && house[k][j] != 0)
				printf("кв.%d (%d ш.е.) ",  (k * rooms + j) + 1, house[k][j]);
			}
		}
		printf("\n");
	}
}