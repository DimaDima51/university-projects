#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int floors = 10; // Этажи
	int rooms = 4; // Квартиры

	int house[floors][rooms];
	int residents = 0;
	
	srand(time(NULL));
	
	for (int i = floors - 1; i >= 0; i--){
		printf("Этаж %d: ", i + 1);
		for(int j = 0; j < rooms; j++){
			house[i][j] = rand()%7;
			printf("%d ", house[i][j]);
			residents += house[i][j];
		}
		printf("\n");
	}
	printf("Всего жильцов: %d => ", residents);
	if (residents > 100) printf("прибавка положена!");
	else printf("прибавка не положена!");
}