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

// ������ �����
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

	fclose(file);
	fclose(tempFile);
	remove("apartment.txt");
	rename("temp.txt", "apartment.txt"); // �������� ������������ ��������� ���� �� apartment
	printf("������ ��������� �������.\n\n");
}

int main() {
	system("cls");
    setlocale(LC_ALL, "RUS");
    int choice;
    do {
        printf("����:\n1. ��������� ������ � ������� �� �����\n2. �������� ������ � �������\n0. �����\n�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
				readDataFromFile(); // �������� ������
                break;
            case 2:
				updateDataInFile(); // �������� ������
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