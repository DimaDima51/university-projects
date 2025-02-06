#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int floors = 10; // Этажи
	int rooms = 4; // Квартиры
	
	int house[floors][rooms];
	
	srand(time(NULL));
	
	for(int i = floors-1; i >= 0; i--){ // Отображение квартир
		printf("Этаж %d: ", i+1);
		for(int j = 0; j < rooms; j++){
			house[i][j] = rand()%7;
			printf("кв.%d - %d ", (i * rooms + j) + 1, house[i][j]);
		}
		printf("\n");
	}
	
	int sampim; // Норма "сампим"
	char term; // Символ для корректности ввода целого числа
	printf("Введите норму \"сампим\": ");
	if ((scanf("%d%c", &sampim, &term) != 2) || (term != '\n')) { // Проверка на корректный ввод целого числа
		printf("Ошибка ввода \"сампима\"!");
		return(-1);
	}
	if (sampim < 1) { // Проверка на существование нормы "сампим"
		printf("Такая норма \"сампима\" быть не может!");
		return(-1);
	}
		
	printf("Квартиры-нарушители: "); // Отображение списка квартир-нарушителей
	for(int i = floors - 1; i >= 0; i--){
		for(int j = 0; j < rooms; j++){
			if (house[i][j] * sampim > 100)
				printf("%d ", (i * rooms + j) + 1);
		}
	}

	int searchRoom; // Номер искомой квартиры
	printf("\nВведите номер квартиры: ");
	if ((scanf("%d%c", &searchRoom, &term) != 2) || (term != '\n')) { // Проверка на корректный ввод целого числа
		printf("Ошибка ввода номера!");
		return(-1);
	}
	if ((searchRoom > floors*rooms) ||(searchRoom < 1)) { // Проверка на существование квартиры в доме
		printf("Такой квартиры в доме не существует!");
		return(-1);
	}
	printf("Жильцов в квартире №%d - %d", searchRoom, house[searchRoom/rooms][searchRoom % rooms - 1]);
}