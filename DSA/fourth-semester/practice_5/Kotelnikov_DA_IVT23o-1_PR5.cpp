#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void printSequence(const vector<int>& seq) {
    for (int num : seq) {
        cout << num << " ";  // выводим каждый элемент
    }
    cout << '\n';
}

// Сортировка Шелла
void shellSort(vector<int>& seq, const vector<int>& gaps, int& swapCount) {
    int n = seq.size();  // получаем размер вектора
    swapCount = 0;       // обнуляем счетчик перестановок
    
    // Проходим по всем шагам из последовательности шагов
    for (int gap : gaps) {
        for (int currIndex = gap; currIndex < n; ++currIndex) {
            int temp = seq[currIndex]; // текущий элемент, который будем вставлять

            int currPos = currIndex; // позиция, на которой находится элемент

            // Пока не вышли за границы и элемент seq[currPos - gap] больше temp
            while (currPos >= gap && temp < seq[currPos - gap]) {
                // Сдвигаем элемент вправо на gap
                seq[currPos] = seq[currPos - gap];
                swapCount++; // увеличиваем счётчик перестановок
                
                // Переходим к предыдущему элементу в подмассиве
                currPos -= gap;
            }

            // Вставляем temp на найденное место
            seq[currPos] = temp;
            if (currPos != currIndex)
                swapCount++; // если было хоть одно смещение
        }
        
        // Выводим промежуточный результат после сортировки с текущим шагом
        cout << "После сортировки с шагом " << gap << ": ";
        printSequence(seq);
    }
}

// Шаг hi+1 = 3*hi + 1: 1, 4, 13, 40, ...
vector<int> generateGaps1(int n) {
    vector<int> gaps;
    int h = 1;
    // Находим максимальный шаг, не превышающий n/9
    while (h <= n / 9) {
        h = 3 * h + 1;
    }
    // Формируем последовательность шагов в обратном порядке
    while (h > 0) {
        gaps.push_back(h);
        h = (h - 1) / 3;
    }
    return gaps;
}

// Шаг hi+1 = 2*hi + 1: 1, 3, 7, 15, ...
vector<int> generateGaps2(int n) {
    vector<int> gaps;
    int h = 1;
    // Находим максимальный шаг, не превышающий n/9
    while (h <= n / 9) {
        h = 2 * h + 1;
    }
    // Формируем последовательность шагов в обратном порядке
    while (h > 0) {
        gaps.push_back(h);
        h = (h - 1) / 2;
    }
    return gaps;
}

// Шаг hi+1 = 2*hi: 1, 2, 4, 8, 16, ...
vector<int> generateGaps3(int n) {
    vector<int> gaps;
    int h = n / 2;  // начинаем с половины размера массива
    // Уменьшаем шаг в два раза на каждой итерации
    while (h > 0) {
        gaps.push_back(h);
        h /= 2;
    }
    return gaps;
}

// Функция разделения для быстрой сортировки
int partition(vector<int>& seq, int left, int right, int& swapCount) {
    int chosen = seq[right];  // в качестве опорного элмента - последний элемент
    int i = left - 1;         // индекс для элементов, меньших опорного
    
    // Перемещаем элементы меньшие опорного влево
    for (int j = left; j < right; ++j) {
        if (seq[j] < chosen) {
            i++;
            swap(seq[i], seq[j]);   // меняем местами элементы
            swapCount++;            // увеличиваем счетчик перестановок
        }
    }

    // Помещаем опорный элемент на его окончательную позицию
    swap(seq[i + 1], seq[right]);
    swapCount++;
    return i + 1;   // индекс опорного элемента
}

// Функция быстрой сортировки
void quickSort(vector<int>& seq, int left, int right, int& swapCount) {
    if (left < right) {
        // Разделяем подмассив и получаем индекс опорного элемента
        int pi = partition(seq, left, right, swapCount);
        
        cout << "Промежуточный результат (главный элемент " << seq[pi] << "): ";
        printSequence(seq);
        
        // Рекурсивно сортируем левую и правую части подмассива
        quickSort(seq, left, pi - 1, swapCount);
        quickSort(seq, pi + 1, right, swapCount);
    }
}

int main() {
    int n;
    cout << "Введите количество элементов для сортировки: ";
    cin >> n;
    
    vector<int> sequence(n);

    srand(time(0));
    for (int i = 0; i < n; ++i) {
        sequence[i] = rand() % 1000;
    }

    cout << "\nИсходная последовательность: ";
    printSequence(sequence);
    
    cout << "\nСортировка Шелла" << '\n';

    // Копии исходного массива для каждой сортировки
    vector<int> seq1 = sequence; 
    vector<int> seq2 = sequence;
    vector<int> seq3 = sequence;
    
    int swapCount1, swapCount2, swapCount3;  // счетчики перестановок для каждой сортировки

    // hi+1 = 3*hi + 1
    cout << "\n1. Последовательность шагов hi+1 = 3*hi + 1:" << '\n';
    vector<int> gaps1 = generateGaps1(n);  // генерируем шаги
    shellSort(seq1, gaps1, swapCount1);    // сортируем
    cout << "Количество перестановок: " << swapCount1 << '\n';
    cout << "Отсортированная последовательность: ";
    printSequence(seq1);  // выводим результат
    
    // hi+1 = 2*hi + 1
    cout << "\n2. Последовательность шагов hi+1 = 2*hi + 1:" << '\n';
    vector<int> gaps2 = generateGaps2(n);
    shellSort(seq2, gaps2, swapCount2);
    cout << "Количество перестановок: " << swapCount2 << '\n';
    cout << "Отсортированная последовательность: ";
    printSequence(seq2);
    
    // hi+1 = 2*hi
    cout << "\n3. Последовательность шагов hi+1 = 2*hi:" << '\n';
    vector<int> gaps3 = generateGaps3(n);
    shellSort(seq3, gaps3, swapCount3);
    cout << "Количество перестановок: " << swapCount3 << '\n';
    cout << "Отсортированная последовательность: ";
    printSequence(seq3);
    
    // Быстрая сортировка
    cout << "\nБыстрая сортировка" << '\n';
    vector<int> quickSeq = sequence;
    int quickSwapCount = 0;
    cout << "\nПроцесс сортировки:" << '\n';
    quickSort(quickSeq, 0, quickSeq.size() - 1, quickSwapCount);
    cout << "\nКоличество перестановок: " << quickSwapCount << '\n';
    cout << "Отсортированная последовательность: ";
    printSequence(quickSeq);
    
    return 0;
}