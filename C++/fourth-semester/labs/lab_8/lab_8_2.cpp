#include <iostream>

class Counter {
    int counter = 0;
public:
    int operator()() {
        return ++counter;
    }
};

int main() {
    Counter count;
    std::cout << count() << '\n'; // 1
    std::cout << count() << '\n'; // 2
    std::cout << count() << '\n'; // 3
}
