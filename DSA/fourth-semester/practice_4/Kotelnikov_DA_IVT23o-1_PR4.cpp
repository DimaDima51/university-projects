#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void mode1_sort_numbers() {
    cout << "Введите количество чисел (n): ";
    int n;
    cin >> n;

    cout << "Введите разряд чисел (k): ";
    int k;
    cin >> k;

    // Минимальное и максимальное значение для заданной разрядности
    int minValue = pow(10, k - 1);
    int maxValue = pow(10, k) - 1;

    vector<int> numbers(n); // набор чисел
    srand(time(0));

    cout << "\nИсходная последовательность:\n";
    for (int i = 0; i < n; ++i) {
        numbers[i] = minValue + rand() % (maxValue - minValue + 1);
        cout << numbers[i] << " ";
    }
    cout << "\n";

    int divisor = 1;
    // Поразрядная сортировка (с наименьшего разряда к наибольшему)
    for (int rank = 0; rank < k; ++rank) {
        vector<vector<int>> tempVec(10); // 10 ячеек для цифр 0–9

        // Распределение чисел по ячейкам в зависимости от текущего разряда
        for (int i = 0; i < n; ++i) {
            int digit = (numbers[i] / divisor) % 10;    // получение цифры из разряда нужного числа
            tempVec[digit].push_back(numbers[i]);       // запись числа в ячейку соответствующей цифры
        }

        // Сборка чисел обратно в исходный массив
        int idx = 0;
        for (int digit = 0; digit < 10; ++digit) {  // проходим по всем цифрам от 0 до 9
            for (int x : tempVec[digit]) {
                numbers[idx++] = x; // перезаписываем набор чисел
            }
        }

        // Вывод текущего состояния после сортировки по текущему разряду
        cout << "После сортировки по разряду " << divisor << ":\n";
        for (int i = 0; i < n; ++i) {
            cout << numbers[i] << " ";
        }
        cout << "\n";

        divisor *= 10; // Переход к следующему разряду
    }

    cout << "\nПолностью отсортированная последовательность чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << " ";
    }
    cout << "\n";
}

void mode2_sort_words() {
    vector<string> words;
    ifstream fin("text.txt");

    string w;
    while (fin >> w) {
        words.push_back(w);
    }
    fin.close();

    int wordLen = words[0].size(); // Длина всех слов
    int m = words.size(); // Количество слов

    cout << "\nИсходная последовательность слов (n = " << m << ", длина каждого слова k = " << wordLen << "):\n";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << "\n";

    // Поразрядная сортировка по символам с конца к началу
    for (int pos = wordLen - 1; pos >= 0; --pos) {
        vector<vector<string>> tempVec(26); // 26 ячеек для каждой буквы английского алфавита

        // Распределение слов по ячейкам по текущей букве
        for (const auto& word : words) {
            char letter = word[pos];
            int idxBucket = letter - 'a'; // индекс ячейки, a-a = 0, b-a = 1, ...
            tempVec[idxBucket].push_back(word); // запись слова в соответствующую ячейку
        }

        // Сборка слов обратно в массив
        int ptr = 0;
        for (int i = 0; i < 26; ++i) {
            for (const auto& s : tempVec[i]) {
                words[ptr++] = s;
            }
        }

        cout << "После сортировки по символу в позиции " << (pos + 1) << " (индекс " << pos << "):\n";
        for (const auto& word : words) {
            cout << word << " ";
        }
        cout << "\n";
    }

    cout << "\nПолностью отсортированная последовательность слов:\n";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << "\n";
}

int main() {
    cout << "Выберите режим работы:\n";
    cout << "1) Случайная генерация чисел и сортировка\n";
    cout << "2) Чтение слов из файла и сортировка\n";
    cout << "Введите 1 или 2: ";

    int mode;
    cin >> mode;

    if (mode == 1) {
        mode1_sort_numbers();
    }
    
    if (mode == 2) {
        mode2_sort_words();
    }

    return 0;
}
