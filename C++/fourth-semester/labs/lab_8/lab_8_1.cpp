// Функциональный объект – это объект класса с переопределённым оператором ().
// Это позволяет использовать объект как функцию.

#include <iostream>

class HelloPrinter {
public:
    void operator()(int times) const {
        for (int i = 0; i < times; ++i)
            std::cout << "Hello\n";
    }
};

int main() {
    HelloPrinter print;   // объект-функтор
    print(3);
    return 0;
}
