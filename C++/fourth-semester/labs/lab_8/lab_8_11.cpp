// Унарная версия

#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> in  = { 5, 10, 15, 20 };      // входные данные
    std::vector<int> out(in.size());               // место для результата

    // Унарная операция: x*3 - 2
    std::transform(in.begin(), in.end(), out.begin(), [](int x) {
        return x * 3 - 2;
    });

    // Выведем результат
    for(int v : out) std::cout << v << ' '; // 13 28 43 58
    std::cout << '\n';
}
