#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	const int MAX_SIZE = 5;
	setlocale(LC_ALL, "RUS");
    int rowsA, columnsA, rowsB, columnsB;

    // Ввод размерности матриц
    printf("Введите количество строк и столбцов матрицы A: ");
    scanf("%d %d", &rowsA, &columnsA);
    printf("Введите количество строк и столбцов матрицы матрицы B: ");
    scanf("%d %d", &rowsB, &columnsB);
	
	if (rowsA < 1 || columnsA < 1 || rowsB < 1 || columnsB < 1){
		printf("Размерность одной из матриц меньше 1!");
		return -1;
	}
	
	if (rowsA > MAX_SIZE || columnsA > MAX_SIZE || rowsB > MAX_SIZE || columnsB > MAX_SIZE){
		printf("Размерность одной из матриц больше 5!");
		return -1;
	}
	
	if (columnsA != rowsB) {
        printf("\nУмножение матриц не возможно, так как количество столбцов матрицы A не равно количеству строк матрицы B.\n");
        return -1;
    }
	
    srand(time(0));
	
    int matrixA[rowsA][columnsA], matrixB[rowsB][columnsB];
	
	// Заполняем матрицу A случайными значениями
	printf("Матрица A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsA; j++) {
            matrixA[i][j] = rand() % 11 - 5;
			printf("%d ", matrixA[i][j]);
        }
		printf("\n");
    }
	
	// Заполняем матрицу B случайными значениями
	printf("Матрица B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < columnsB; j++) {
            matrixB[i][j] = rand() % 11 - 5;
			printf("%d ", matrixB[i][j]);
        }
		printf("\n");
    }
	
	// Матрица C - результат умножения матрицы A и B
	int matrixC[rowsA][columnsB];

	printf("Вычисляем матрицу C = A*B (размерность %d x %d)\n", rowsA, columnsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            matrixC[i][j] = 0;
			printf("c[%d,%d] ", i, j);
            for (int k = 0; k < columnsA; k++) {
				if (k == 0) printf("= ");
				else printf("+ ");
                printf("%d*%d ", matrixA[i][k], matrixB[k][j]);
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
            printf("= %d\n", matrixC[i][j]);
        }
    }

	// Вывод матрицы C
	printf("Результат - матрица C = A*B (размерность %d x %d)\n", rowsA, columnsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    
	// Транспонированная матрица C 
	int transposeC[columnsB][rowsA];

	// Транспонирование матрицы
    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < columnsB; ++j) {
            transposeC[j][i] = matrixC[i][j];
	}

    // Вывод транспонированной матрицы
    printf("Транспонированная матрица C:\n");
    for (int i = 0; i < columnsB; ++i)
        for (int j = 0; j < rowsA; ++j) {
            printf("%d  ", transposeC[i][j]);
            if (j == rowsA - 1)
                printf("\n");
	}
}
