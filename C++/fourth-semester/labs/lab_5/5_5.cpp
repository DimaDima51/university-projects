#include <iostream>

using namespace std;

// Пересечение двух массивов
template <typename T> 
int my_intersection(int m, int n, T* a, T* b, T* result) {
    int len = 0;
    for (int i = 0; i < m; i++) {
        // Проверяем, есть ли текущий элемент из a в массиве b
        bool found_in_b = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                found_in_b = true;
                break;
            }
        }
        
        // Проверяем, не добавлен ли уже этот элемент в результат
        bool already_in_result = false;
        for (int k = 0; k < len; k++) {
            if (result[k] == a[i]) {
                already_in_result = true;
                break;
            }
        }
        
        // Если элемент есть в обоих массивах и еще не в результате - добавляем
        if (found_in_b && !already_in_result) {
            result[len++] = a[i];
        }
    }
    return len;
}

// Объединение двух массивов
template <typename T> 
int my_union(int m, int n, T* a, T* b, T* result) {
    int len = 0;
    
    // Добавляем уникальные элементы из первого массива
    for (int i = 0; i < m; i++) {
        bool already_in_result = false;
        for (int k = 0; k < len; k++) {
            if (result[k] == a[i]) {
                already_in_result = true;
                break;
            }
        }
        if (!already_in_result) {
            result[len++] = a[i];
        }
    }
    
    // Добавляем уникальные элементы из второго массива
    for (int i = 0; i < n; i++) {
        bool already_in_result = false;
        for (int k = 0; k < len; k++) {
            if (result[k] == b[i]) {
                already_in_result = true;
                break;
            }
        }
        if (!already_in_result) {
            result[len++] = b[i];
        }
    }
    
    return len;
}

// Разность массивов (A \ B)
template <typename T> 
int my_difference(int m, int n, T* a, T* b, T* result) {
    int len = 0;
    
    for (int i = 0; i < m; i++) {
        // Проверяем, есть ли текущий элемент из a в массиве b
        bool found_in_b = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                found_in_b = true;
                break;
            }
        }
        
        // Проверяем, не добавлен ли уже этот элемент в результат
        bool already_in_result = false;
        for (int k = 0; k < len; k++) {
            if (result[k] == a[i]) {
                already_in_result = true;
                break;
            }
        }
        
        // Если элемента нет в b и его еще нет в результате - добавляем
        if (!found_in_b && !already_in_result) {
            result[len++] = a[i];
        }
    }
    
    return len;
}

int main() {
    int m = 4, n = 4;
    int* a = new int[m] {1, 2, 3, 4};
    int* b = new int[n] {3, 4, 5, 6};
    int* result = new int[m + n];
    
    cout << "Массив A: ";
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    
    cout << "Массив B: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << '\n';
    
    int p = my_intersection(m, n, a, b, result);
    cout << "Пересечение: ";
    for (int i = 0; i < p; i++) {
        cout << result[i] << " ";
    }
    cout << '\n';

    p = my_union(m, n, a, b, result);
    cout << "Объединение: ";
    for (int i = 0; i < p; i++) {
        cout << result[i] << " ";
    }
    cout << '\n';
    
    p = my_difference(m, n, a, b, result);
    cout << "Разность A \\ B: ";
    for (int i = 0; i < p; i++) {
        cout << result[i] << " ";
    }
    cout << '\n';
    
    delete[] a;
    delete[] b;
    delete[] result;
    
    return 0;
}