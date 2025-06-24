// Бинарная функция – это функтор, который можно вызвать с двумя аргументами.

#include <iostream>

struct Add {
    int operator()(int a, int b) const { // два аргумента
        return a + b;
    }
};

int main() {
    Add add;
    std::cout << add(3, 4) << '\n'; // 7
}
