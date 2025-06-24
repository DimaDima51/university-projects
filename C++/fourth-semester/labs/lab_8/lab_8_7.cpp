// Бинарный предикат – это функтор, который принимает два аргумента и возвращает bool.

#include <iostream>

struct Greater {
    bool operator()(int a, int b) const { // 1 если a > b
        return a > b;
    }
};

int main() {
    Greater gt;
    std::cout << gt(5, 3) << ' ' << gt(2, 7) << '\n';
}
