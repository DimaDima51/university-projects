// Предикат – это функтор, который принимает один аргумент и возвращает значение типа bool.

#include <iostream>

struct IsEven {
    bool operator()(int x) const { // 1 если чётное
        return x % 2 == 0;
    }
};

int main() {
    IsEven pred;
    std::cout << pred(4) << ' ' << pred(7) << '\n';
}
