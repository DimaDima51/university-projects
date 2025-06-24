#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// first - индекс корня подкучи
// last - индекс последнего элемента в подкуче
// arr - массив-куча
// swaps - ссылка на счётчик перестановок для этой итерации
void heapify(int first, int last, std::vector<int>& arr, int& swaps) {
    int largest = first;
    int left = 2 * first + 1; // левый потомок
    int right = 2 * first + 2; // правый потомок

    // Найти наибольший из корня и потомков
    if (left <= last && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= last && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший не корень - поменять и рекурсивно продолжить
    if (largest != first) {
        std::swap(arr[first], arr[largest]);
        ++swaps;
        heapify(largest, last, arr, swaps);
    }
}

// Построение макс-кучи из исходного массива
// arr - исходный массив
void buildMaxHeap(std::vector<int>& arr) {
    int n = arr.size();
    // Проходим по всем неперечисленным узлам с конца
    for (int i = n / 2 - 1; i >= 0; --i) {
        int temp = 0; // при построении начальной кучи перестановки не считаем
        heapify(i, n - 1, arr, temp);
    }
}

int main() {
    std::srand(time(0));

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 101 - 50;
    }

    std::cout << "\nИсходный массив:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i + 1 < n ? ", " : "\n");
    }

    // Строим максимальную кучу
    buildMaxHeap(arr);

    // Основной цикл сортировки кучей
    // На каждой итерации извлекаем максимальный элемент (arr[0])
    for (int i = n - 1; i > 0; --i) {
        int swaps = 0; // счётчик перестановок в этой итерации 

        // Переставляем корень (максимум) и последний элемент неотсортированной части
        std::swap(arr[0], arr[i]);
        ++swaps;

        // Восстанавливаем структуру кучи на отрезке [0..i-1]
        heapify(0, i - 1, arr, swaps);

        std::cout << "\nПосле выбора максимума для позиции " << i << " (перестановок " << swaps << "):\n";
        for (int j = 0; j < n; ++j) {
            std::cout << arr[j] << (j + 1 < n ? ", " : "\n");
        }
    }

    std::cout << "\nСортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i + 1 < n ? ", " : "\n");
    }

    return 0;
}
