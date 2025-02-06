#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int n; // Размер массива
	char term;
	printf("Введите размер массива: ");
	if ((scanf("%d%c", &n, &term) != 2) || (term != '\n')) { // Проверка на корректный ввод целого числа
		printf("Ошибка ввода размера массива!");
		return(-1);
	}
	
	if (n < 1) {
		printf("Массива с заданным значением размера не существует!");
		return(-1);
	}
	
	int array[n]; // Объявление массива размером n
	int max_abs = 0; // Максимальное по модулю
	int min_val = 0; // Минимальное по значению
	int sum = 0; // Сумма чисел массива
	int count = 0; // Количество чисел больше среднего арифметического
	
	srand(time(NULL));
	
	printf("Массив: ");
	for (int i = 0; i < n; i++){
		array[i] = rand()%101 - 50;
		printf("%d ", array[i]); // Вывод элемента массива
		
		if (abs(array[i]) > max_abs) // Нахождение максимального по модулю
			max_abs = abs(array[i]);
		
		if (array[i] < min_val) // Нахождение минимального по значению
			min_val = array[i];
		
		sum += array[i]; // Нахождение суммы элементов массива
	}
	
	float avg = ((float)sum/(float)n); // Среднее арифметическое
	
	for (int i = 0; i < n; i++) // Подсчет чисел больше среднего арифметического
		if (array[i] > avg) count++;
			
	printf("\nМаксимальный по модулю: %d\n", max_abs);
	printf("Минимальный по значению: %d\n", min_val);
	printf("Среднее арифметическое: %.3f\n", avg);
	printf("Количество чисел больше среднего арифметического: %d\n", count);
}