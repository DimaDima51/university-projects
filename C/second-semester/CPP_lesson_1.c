#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define FLOORS 10
#define ROOMS 4

// ��������� ����� 
typedef struct {
    int floorNumber;
    int numResidents[ROOMS];
} Floor;

// ����� ������ ������ ����� �� �������� ��������
int findFloor(int apartmentNum) {
    int floor = (apartmentNum - 1) / ROOMS + 1;
    return floor;
}

// ����� �������� ������� �� �����
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

// ����� ���������� ������ �� ���������� �������
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
                // ����� �������
                Floor temp = floors[j];
                floors[j] = floors[j + 1];
                floors[j + 1] = temp;
            }
        }
    }
}

// ����� ��������� �� ������� ��� ������ ������ ��������� ������ �������
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
        printf("\n5. ������� ���������� ������� ��������� �� ������� ������ (� 6 �� 10) �� %d.", upperResidents - lowerResidents);
    } else if (lowerResidents > upperResidents) {
        printf("\n5. ������� ���������� ������� ��������� �� ������ ������ (� 1 �� 5) �� %d.", lowerResidents - upperResidents);
    } else {
        printf("\n5. �� ������� � ������ ������ ������� ��������� ���������� ����������.");
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    Floor floors[FLOORS];
    for (int i = 0; i < FLOORS; i++) {
		printf("���� %d: ", i + 1);
        floors[i].floorNumber = i + 1;
        for (int j = 0; j < ROOMS; j++) {
            floors[i].numResidents[j] = rand() % 6;
			printf("��.%d - %d ", (i * ROOMS + j) + 1, floors[i].numResidents[j]);
        }
		printf("\n");
    }

	// ����� ����� �������� ��������
    int apartmentNum;
    printf("\n1. ������� ����� �������� ��� ����������� ��� �����: ");
    scanf("%d", &apartmentNum);
    int floorNum = findFloor(apartmentNum);
    printf("�������� ����� %d ��������� �� %d �����.\n", apartmentNum, floorNum);

	// ������� ������� �� �����
    int requestedFloor;
    printf("\n2. ������� ����� ����� ��� �������� ������� �� �����: ");
    scanf("%d", &requestedFloor);
    int numResidents = findNumResidents(floors, FLOORS, requestedFloor);
	printf("�� %d ����� �������: %d\n", requestedFloor, numResidents);

	// ����� ������� �� ���������� �������
    int requestedResidents;
    printf("\n3. ������� ���������� ������� ��� ������ �������: ");
    scanf("%d", &requestedResidents);

    printf("�������� � %d ��������:\n", requestedResidents);
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            if (floors[i].numResidents[j] == requestedResidents) {
                int apartmentNumInArray = i*ROOMS + j + 1;
                printf("�������� �%d (���� %d) \n", apartmentNumInArray, i + 1);
            }
        }
    }

	// ���������� ���� �� �������  
	sortFloorsByResidents(floors, FLOORS);
	
	// ����������� �������������� ����
    printf("\n4. �����, ��������������� �� ���������� �������:\n");
    for (int i = 0; i < FLOORS; i++) {
        int totalResidents = 0;
        for (int j = 0; j < ROOMS; j++) {
            totalResidents += floors[i].numResidents[j];
        }
        printf("���� %d - %d \n", floors[i].floorNumber, totalResidents);
    }
	
	// ������� ������� �� ������� � ������ ������
	compareResidentsOnFloors(floors, FLOORS);
	
    return 0;
}