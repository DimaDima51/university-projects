// Используется унарный предикат, который возвращает true для тех значений,
// которые необходимо удалить из list, и false для остальных.

#include <list>
#include <iostream>

// Унарный предикат: удаляет все отрицательные числа
struct IsNegative {
    bool operator()(int x) const {
        return x < 0;
    }
};

int main() {
    std::list<int> lst = { 3, -1, 4, -5, 2, -8, 0 };

    // До: 3, -1, 4, -5, 2, -8, 0
    lst.remove_if(IsNegative());  // передаём функтор‑предикат

    // После: 3, 4, 2, 0
    for (int x : lst) 
        std::cout << x << ' ';
    std::cout << '\n';
}
