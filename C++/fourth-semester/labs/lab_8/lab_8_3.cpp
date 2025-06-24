// Генератор – это функтор, который может быть вызван без аргументов.

#include <iostream>

struct Counter {
    int value = 0;
    int operator()() {  // nullary operator()
        return value++; // возвращает текущее и увеличивает
    }
};

int main() {
    Counter gen;
    std::cout << gen() << '\n'; // 0
    std::cout << gen() << '\n'; // 1
    std::cout << gen() << '\n'; // 2
}
