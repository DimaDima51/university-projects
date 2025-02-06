#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define FLOORS 10
#define ROOMS 4

// Структура квартиры: номер, фамилия, число жильцов
typedef struct {
    int apartmentNumber;
    char lastName[30];
    int numResidents;
} ApartStruct;

// Чтение файла
void readDataFromFile() {
	int apartmentNumber;
	printf("Введите номер квартиры для чтения: ");
	scanf("%d", &apartmentNumber);

	// открываем файл
	FILE *file = fopen("apartment.txt", "r");
	if (file == NULL) { // если файл не удаётся открыть, то fopen вернёт NULL
		printf("Ошибка при чтении файла!\n");
		exit(1);
	}

	ApartStruct apartment;

	while (fscanf(file, "%d;%[^;];%d\n", &apartment.apartmentNumber, &apartment.lastName, &apartment.numResidents) == 3) { // читаем весь файл
		if (apartment.apartmentNumber == apartmentNumber) { // при нахождении искомой квартиры отображаем её данные
			printf("\nКвартира: %d\nФамилия: %s\nКоличество жильцов: %d\n\n", apartment.apartmentNumber, apartment.lastName, apartment.numResidents);
			break;
		}
	}
	fclose(file);
}

// Обновление данных в файле
void updateDataInFile() {
	int apartmentNumber, numResidents;
	char lastName[30];
	printf("Введите номер квартиры для изменения данных: ");

	scanf("%d", &apartmentNumber);
	printf("Введите фамилию нового жильца: ");
	scanf("%s", &lastName);
	printf("Введите количество жильцов: ");
	scanf("%d", &numResidents);
	
	// открываем файлы
	FILE *file = fopen("apartment.txt", "r");
	FILE *tempFile = fopen("temp.txt", "w"); //временный файл для перезаписи
	
	if (file == NULL || tempFile == NULL) { // если файлы не удаётся открыть, то fopen вернёт NULL
		printf("Ошибка при чтении файла!\n");
		exit(1);
	}

	ApartStruct apartment;

	// перезаписываем данные из apartment в temp
	while (fscanf(file, "%d;%[^;];%d\n", &apartment.apartmentNumber, &apartment.lastName, &apartment.numResidents) == 3) {
		if (apartment.apartmentNumber == apartmentNumber) // если попадается номер редактируемой квартиры, то записываем новые данные	
			fprintf(tempFile, "%d;%s;%d\n", apartmentNumber, lastName, numResidents); 			
		else // иначе записываем прошлые данные
			fprintf(tempFile, "%d;%s;%d\n", apartment.apartmentNumber, apartment.lastName, apartment.numResidents);
	}

	fclose(file);
	fclose(tempFile);
	remove("apartment.txt");
	rename("temp.txt", "apartment.txt"); // заменяем переписанный временный файл на apartment
	printf("Данные обновлены успешно.\n\n");
}

int main() {
	system("cls");
    setlocale(LC_ALL, "RUS");
    int choice;
    do {
        printf("Меню:\n1. Прочитать данные о жильцах из файла\n2. Изменить данные о жильцах\n0. Выйти\nВыберите действие: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
				readDataFromFile(); // прочесть данные
                break;
            case 2:
				updateDataInFile(); // обновить данные
                break;
            case 0:
                printf("До свидания!\n");
                break;
            default:
                printf("Некорректный выбор. Пожалуйста, выберите существующий пункт меню.\n");
        }
    } while (choice != 0);

    return 0;
}