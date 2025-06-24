// Бинарная версия

#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> a = { 10, 20, 30, 40 };   // первый вектор
    std::vector<int> b = { 1, 2, 3, 4 };   // второй вектор
    std::vector<int> c(a.size());              // результат

    // Бинарная операция: (a_i - b_i) * 2
    std::transform(a.begin(), a.end(), b.begin(), c.begin(), [](int x, int y) {
        return (x - y) * 2;
    });

    // Выведем результат
    for(int v : c) std::cout << v << ' '; // 18 36 54 72
    std::cout << '\n';
}
