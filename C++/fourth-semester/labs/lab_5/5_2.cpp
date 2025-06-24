#include <iostream>

using namespace std;

// Максимум из двух объектов
template <typename T> 
T& max(T &m, T &n) {
    return (m > n) ? m : n;
}

// Максимум из трёх объектов
template <typename T> 
T& max(T &m, T &n, T &p) {
    return max(m, max(n, p));
}

// Шаблонная функция
template <typename T>
T*& max(T*& s1, T*& s2);

// Специализированная функция шаблона для сравнения строк
template <>
char*& max<char>(char *&s1, char *&s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            return s1;
        }
        else if (s1[i] < s2[i]) {
            return s2;
        }
        i++;
    }
    return (s1[i] != '\0') ? s1 : s2;
}

int main() {
    int a = 10, b = 15, c = 20;
    cout << "int (2): " << max(a, b) << "\n";
    
    cout << "int (3): " << max(a, b, c) << "\n";   

    string x = "apple", y = "cats";
    cout << "string: " << max(x, y) << "\n";
    
    return 0;
}