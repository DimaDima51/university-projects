#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define FLOORS 10
#define ROOMS 4

// ��������� ��������: �����, �������, ����� �������
typedef struct {
    int apartmentNumber;
    char lastName[30];
    int numResidents;
} ApartStruct;

// ������ ������ ���������� ��������
void readDataFromFile() {
	int apartmentNumber;
	printf("������� ����� �������� ��� ������: ");
	scanf("%d", &apartmentNumber);

	// ��������� ����
	FILE *file = fopen("apartment.txt", "r");
	if (file == NULL) { // ���� ���� �� ������ �������, �� fopen ����� NULL
		printf("������ ��� ������ �����!\n");
		exit(1);
	}

	ApartStruct apartment;

	while (fscanf(file, "%d;%[^;];%d\n", &apartment.apartmentNumber, &apartment.lastName, &apartment.numResidents) == 3) { // ������ ���� ����
		if (apartment.apartmentNumber == apartmentNumber) { // ��� ���������� ������� �������� ���������� � ������
			printf("\n��������: %d\n�������: %s\n���������� �������: %d\n\n", apartment.apartmentNumber, apartment.lastName, apartment.numResidents);
			break;
		}
	}
	
	// ��������� �����
	fclose(file);
}

// ���������� ������ � �����
void updateDataInFile() {
	int apartmentNumber, numResidents;
	char lastName[30];
	printf("������� ����� �������� ��� ��������� ������: ");

	scanf("%d", &apartmentNumber);
	printf("������� ������� ������ ������: ");
	scanf("%s", &lastName);
	printf("������� ���������� �������: ");
	scanf("%d", &numResidents);
	
	// ��������� �����
	FILE *file = fopen("apartment.txt", "r");
	FILE *tempFile = fopen("temp.txt", "w"); //��������� ���� ��� ����������
	
	if (file == NULL || tempFile == NULL) { // ���� ����� �� ������ �������, �� fopen ����� NULL
		printf("������ ��� ������ �����!\n");
		exit(1);
	}

	ApartStruct apartment;

	// �������������� ������ �� apartment � temp
	while (fscanf(file, "%d;%[^;];%d\n", &apartment.apartmentNumber, &apartment.lastName, &apartment.numResidents) == 3) {
		if (apartment.apartmentNumber == apartmentNumber) // ���� ���������� ����� ������������� ��������, �� ���������� ����� ������	
			fprintf(tempFile, "%d;%s;%d\n", apartmentNumber, lastName, numResidents); 			
		else // ����� ���������� ������� ������
			fprintf(tempFile, "%d;%s;%d\n", apartment.apartmentNumber, apartment.lastName, apartment.numResidents);
	}

	// ��������� ������
	fclose(file);
	fclose(tempFile);
	
	remove("apartment.txt");
	rename("temp.txt", "apartment.txt"); // �������� ������������ ��������� ���� �� apartment
	printf("������ ��������� �������.\n\n");
}

// ����������� ���� �������
void showDateFromFile() {
	// ��������� ����
	FILE *file = fopen("apartment.txt", "r");
	if (file == NULL) { // ���� ���� �� ������ �������, �� fopen ����� NULL
		printf("������ ��� ������ �����!\n");
		exit(1);
	}

    ApartStruct apartments[FLOORS*ROOMS];
    int numApartments = 0;

    while (fscanf(file, "%d;%[^;];%d\n", &apartments[numApartments].apartmentNumber, apartments[numApartments].lastName, &apartments[numApartments].numResidents) == 3) {
        numApartments++;
    }

    fclose(file);

    for (int i = 0; i < numApartments; i++) {
        printf("\n�������� � %d\n�������: %s\n���-�� �������: %d\n", apartments[i].apartmentNumber, apartments[i].lastName, apartments[i].numResidents);
    }
}

// ���������� � ����������� ������ ������� �� ���������� ������� � ������� �����������
void sortAndShowDateFromFile() {
	
	// ��������� ����
	FILE *file = fopen("apartment.txt", "r");
	if (file == NULL) { // ���� ���� �� ������ �������, �� fopen ����� NULL
		printf("������ ��� ������ �����!\n");
		exit(1);
	}

    ApartStruct apartments[FLOORS*ROOMS];
    int numApartments = 0;

    while (fscanf(file, "%d;%[^;];%d\n", &apartments[numApartments].apartmentNumber, apartments[numApartments].lastName, &apartments[numApartments].numResidents) == 3) {
        numApartments++;
    }

    fclose(file);

    // ���������� ���������
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
        printf("\n%d) �������� � %d\n�������: %s\n���-�� �������: %d\n", i+1, apartments[i].apartmentNumber, apartments[i].lastName, apartments[i].numResidents);
    }
}

// ���������� � ����������� ������ ������� �� ���������� ������� � ������� ����������� � ����������
void sortAndShowDateFromFileWithNumb() {
	
	printf("������� k ���������� ������� ��� �����������: ");

	int numToShow;
	scanf("%d", &numToShow);
	
	// ��������� ����
	FILE *file = fopen("apartment.txt", "r");
	if (file == NULL) { // ���� ���� �� ������ �������, �� fopen ����� NULL
		printf("������ ��� ������ �����!\n");
		exit(1);
	}

    ApartStruct apartments[FLOORS*ROOMS];
    int numApartments = 0;

    while (fscanf(file, "%d;%[^;];%d\n", &apartments[numApartments].apartmentNumber, apartments[numApartments].lastName, &apartments[numApartments].numResidents) == 3) {
        numApartments++;
    }

    fclose(file);

    // ���������� ���������
    for (int i = 0; i < numApartments - 1; i++) {
        for (int j = 0; j < numApartments - i - 1; j++) {
            if (apartments[j].numResidents > apartments[j + 1].numResidents) {
                ApartStruct temp = apartments[j];
                apartments[j] = apartments[j + 1];
                apartments[j + 1] = temp;
            }
        }
    }

    printf("\n����� ���������� � ������ %d ���������:\n", numToShow);
    for (int i = 0; i < numToShow && i < numApartments; i++) {
        printf("\n%d) �������� � %d\n�������: %s\n���-�� �������: %d\n", i+1, apartments[i].apartmentNumber, apartments[i].lastName, apartments[i].numResidents);
    }
}

int main() {
	system("cls");
    setlocale(LC_ALL, "RUS");
    int choice;
    do {
        printf("\n����:\n1. ��������� ������ � ������� �� ����� (�� 3-4)\n2. �������� ������ � ������� (�� 3-4)\n3. ������� ��� �������� (�� 5)\n4. ������� ��������������� �������� (�� 5)\n5. ������� ������ k ����� ��������������� �������\n0. �����\n�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
				readDataFromFile(); // �������� ������
                break;
            case 2:
				updateDataInFile(); // �������� ������
                break;
			case 3:
				showDateFromFile(); // ����������� ���� �������
				break;
			case 4:
				sortAndShowDateFromFile(); // ���������� ������� �� ���������� �������
				break;
			case 5:
				sortAndShowDateFromFileWithNumb(); // ���������� ������� �� ���������� ������� � ����������
				break;
            case 0:
                printf("�� ��������!\n");
                break;
            default:
                printf("������������ �����. ����������, �������� ������������ ����� ����.\n");
        }
    } while (choice != 0);

    return 0;
}