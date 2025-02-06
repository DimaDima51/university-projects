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

// Чтение данных конкретной квартиры
void readDataFromFile() {
	int apartmentNumber;
	printf("Введите номер квартиры для чтения: ");
	scanf("%d", &apartmentNumber);

	// Открываем файл
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
	
	// Закрываем поток
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

	// Закрываем потоки
	fclose(file);
	fclose(tempFile);
	
	remove("apartment.txt");
	rename("temp.txt", "apartment.txt"); // заменяем переписанный временный файл на apartment
	printf("Данные обновлены успешно.\n\n");
}

// Отображение всех квартир
void showDateFromFile() {
	// Открываем файл
	FILE *file = fopen("apartment.txt", "r");
	if (file == NULL) { // если файл не удаётся открыть, то fopen вернёт NULL
		printf("Ошибка при чтении файла!\n");
		exit(1);
	}

    ApartStruct apartments[FLOORS*ROOMS];
    int numApartments = 0;

    while (fscanf(file, "%d;%[^;];%d\n", &apartments[numApartments].apartmentNumber, apartments[numApartments].lastName, &apartments[numApartments].numResidents) == 3) {
        numApartments++;
    }

    fclose(file);

    for (int i = 0; i < numApartments; i++) {
        printf("\nКвартира № %d\nФамилия: %s\nКол-во жильцов: %d\n", apartments[i].apartmentNumber, apartments[i].lastName, apartments[i].numResidents);
    }
}

// Сортировка и отображение списка квартир по количеству жителей в порядке возрастания
void sortAndShowDateFromFile() {
	
	// Открываем файл
	FILE *file = fopen("apartment.txt", "r");
	if (file == NULL) { // если файл не удаётся открыть, то fopen вернёт NULL
		printf("Ошибка при чтении файла!\n");
		exit(1);
	}

    ApartStruct apartments[FLOORS*ROOMS];
    int numApartments = 0;

    while (fscanf(file, "%d;%[^;];%d\n", &apartments[numApartments].apartmentNumber, apartments[numApartments].lastName, &apartments[numApartments].numResidents) == 3) {
        numApartments++;
    }

    fclose(file);

    // Сортировка пузырьком
    for (int i = 0; i < numApartments - 1; i++) {
        for (int j = 0; j < numApartments - i - 1; j++) {
            if (apartments[j].numResidents > apartments[j + 1].numResidents) {
                ApartStruct temp = apartments[j];
                apartments[j] = apartments[j + 1];
                apartments[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < numApartments; i++) {
        printf("\n%d) Квартира № %d\nФамилия: %s\nКол-во жильцов: %d\n", i+1, apartments[i].apartmentNumber, apartments[i].lastName, apartments[i].numResidents);
    }
}

// Сортировка и отображение списка квартир по количеству жителей в порядке возрастания с диапазоном
void sortAndShowDateFromFileWithNumb() {
	
	printf("Введите k количество квартир для отображения: ");

	int numToShow;
	scanf("%d", &numToShow);
	
	// Открываем файл
	FILE *file = fopen("apartment.txt", "r");
	if (file == NULL) { // если файл не удаётся открыть, то fopen вернёт NULL
		printf("Ошибка при чтении файла!\n");
		exit(1);
	}

    ApartStruct apartments[FLOORS*ROOMS];
    int numApartments = 0;

    while (fscanf(file, "%d;%[^;];%d\n", &apartments[numApartments].apartmentNumber, apartments[numApartments].lastName, &apartments[numApartments].numResidents) == 3) {
        numApartments++;
    }

    fclose(file);

    // Сортировка пузырьком
    for (int i = 0; i < numApartments - 1; i++) {
        for (int j = 0; j < numApartments - i - 1; j++) {
            if (apartments[j].numResidents > apartments[j + 1].numResidents) {
                ApartStruct temp = apartments[j];
                apartments[j] = apartments[j + 1];
                apartments[j + 1] = temp;
            }
        }
    }

    printf("\nВывод информации о первых %d квартирах:\n", numToShow);
    for (int i = 0; i < numToShow && i < numApartments; i++) {
        printf("\n%d) Квартира № %d\nФамилия: %s\nКол-во жильцов: %d\n", i+1, apartments[i].apartmentNumber, apartments[i].lastName, apartments[i].numResidents);
    }
}

int main() {
	system("cls");
    setlocale(LC_ALL, "RUS");
    int choice;
    do {
        printf("\nМеню:\n1. Прочитать данные о жильцах из файла (ПР 3-4)\n2. Изменить данные о жильцах (ПР 3-4)\n3. Вывести все квартиры (ПР 5)\n4. Вывести отсортированные квартиры (ПР 5)\n5. Вывести первые k число отсортированных квартир\n0. Выйти\nВыберите действие: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
				readDataFromFile(); // Прочесть данные
                break;
            case 2:
				updateDataInFile(); // Обновить данные
                break;
			case 3:
				showDateFromFile(); // Отображение всех квартир
				break;
			case 4:
				sortAndShowDateFromFile(); // Сортировка квартир по количеству человек
				break;
			case 5:
				sortAndShowDateFromFileWithNumb(); // Сортировка квартир по количеству человек с диапазоном
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