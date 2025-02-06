#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define FLOORS 10
#define ROOMS 4

// Структура этажа 
typedef struct {
    int floorNumber;
    int numResidents[ROOMS];
} Floor;

// Метод поиска номера этажа по заданной квартире
int findFloor(int apartmentNum) {
    int floor = (apartmentNum - 1) / ROOMS + 1;
    return floor;
}

// Метод подсчёта жителей на этаже
int findNumResidents(Floor *floors, int numFloors, int requestedFloor) {
    for (int i = 0; i < numFloors; i++) {
        if (floors[i].floorNumber == requestedFloor) {
            int totalResidents = 0;
            for (int j = 0; j < ROOMS; j++) {
                totalResidents += floors[i].numResidents[j];
            }
            return totalResidents;
        }
    }
    return -1;
}

// Метод сортировки этажей по количеству жильцов
void sortFloorsByResidents(Floor *floors, int numFloors) {
    for (int i = 0; i < numFloors - 1; i++) {
        for (int j = 0; j < numFloors - i - 1; j++) {
            int totalResidentsA = 0;
            int totalResidentsB = 0;
            for (int k = 0; k < ROOMS; k++) {
                totalResidentsA += floors[j].numResidents[k];
                totalResidentsB += floors[j + 1].numResidents[k];
            }
            if (totalResidentsA < totalResidentsB) {
                // Обмен местами
                Floor temp = floors[j];
                floors[j] = floors[j + 1];
                floors[j + 1] = temp;
            }
        }
    }
}

// Метод сравнения на верхних или нижних этажах проживает больше жителей
void compareResidentsOnFloors(Floor *floors, int numFloors) {
    int upperResidents = 0;
    int lowerResidents = 0;
    
    for (int i = 0; i < numFloors; i++) {
        int totalResidents = 0;
        for (int j = 0; j < ROOMS; j++) {
            totalResidents += floors[i].numResidents[j];
        }
        
        if (floors[i].floorNumber >= 1 && floors[i].floorNumber <= 5) {
            lowerResidents += totalResidents;
        } else if (floors[i].floorNumber >= 6 && floors[i].floorNumber <= 10) {
            upperResidents += totalResidents;
        }
    }
    
    if (upperResidents > lowerResidents) {
        printf("\n5. Большее количество жильцов проживает на верхних этажах (с 6 по 10) на %d.", upperResidents - lowerResidents);
    } else if (lowerResidents > upperResidents) {
        printf("\n5. Большее количество жильцов проживает на нижних этажах (с 1 по 5) на %d.", lowerResidents - upperResidents);
    } else {
        printf("\n5. На верхних и нижних этажах жильцов проживает одинаковое количество.");
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    Floor floors[FLOORS];
    for (int i = 0; i < FLOORS; i++) {
		printf("Этаж %d: ", i + 1);
        floors[i].floorNumber = i + 1;
        for (int j = 0; j < ROOMS; j++) {
            floors[i].numResidents[j] = rand() % 6;
			printf("кв.%d - %d ", (i * ROOMS + j) + 1, floors[i].numResidents[j]);
        }
		printf("\n");
    }

	// Поиск этажа заданной квартиры
    int apartmentNum;
    printf("\n1. Введите номер квартиры для отображения его этажа: ");
    scanf("%d", &apartmentNum);
    int floorNum = findFloor(apartmentNum);
    printf("Квартира номер %d находится на %d этаже.\n", apartmentNum, floorNum);

	// Подсчёт жильцов на этаже
    int requestedFloor;
    printf("\n2. Введите номер этажа для подсчёта жильцов на этаже: ");
    scanf("%d", &requestedFloor);
    int numResidents = findNumResidents(floors, FLOORS, requestedFloor);
	printf("На %d этаже жильцов: %d\n", requestedFloor, numResidents);

	// Поиск квартир по количеству жильцов
    int requestedResidents;
    printf("\n3. Введите количество жильцов для поиска квартир: ");
    scanf("%d", &requestedResidents);

    printf("Квартиры с %d жильцами:\n", requestedResidents);
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            if (floors[i].numResidents[j] == requestedResidents) {
                int apartmentNumInArray = i*ROOMS + j + 1;
                printf("Квартира №%d (этаж %d) \n", apartmentNumInArray, i + 1);
            }
        }
    }

	// Сортировка дома по жителям  
	sortFloorsByResidents(floors, FLOORS);
	
	// Отображение сортированного дома
    printf("\n4. Этажи, отсортированные по количеству жильцов:\n");
    for (int i = 0; i < FLOORS; i++) {
        int totalResidents = 0;
        for (int j = 0; j < ROOMS; j++) {
            totalResidents += floors[i].numResidents[j];
        }
        printf("Этаж %d - %d \n", floors[i].floorNumber, totalResidents);
    }
	
	// Подсчет жильцов на верхних и нижних этажах
	compareResidentsOnFloors(floors, FLOORS);
	
    return 0;
}