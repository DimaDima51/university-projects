// Унарная функция – это функтор, который принимает один аргумент.

#include <iostream>

struct Square {
    int operator()(int x) const { // один аргумент
        return x * x;
    }
};

int main() {
    Square sq;
    std::cout << sq(5) << '\n'; // 25
}
