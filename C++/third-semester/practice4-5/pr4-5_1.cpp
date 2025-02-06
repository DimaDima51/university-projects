/*
Реализовать функцию swap (обмен значений) со следующим прототипом: void swap(int **a, int **b);
*/

#include <iostream>

void swap(int **a, int **b) {
    int *temp = *a; // Сохраняем указатель на int из a
    *a = *b;        // Меняем указатель a на указатель b
    *b = temp;     // Меняем указатель b на сохраненный указатель
}

int main() {
    int x = 10;
    int y = 20;

    int *ptrA = &x;
    int *ptrB = &y;

    std::cout << "До: ptrA = " << *ptrA << ", ptrB = " << *ptrB << std::endl;

    swap(&ptrA, &ptrB); // Передаем адреса указателей

    std::cout << "После: ptrA = " << *ptrA << ", ptrB = " << *ptrB << std::endl;
}
