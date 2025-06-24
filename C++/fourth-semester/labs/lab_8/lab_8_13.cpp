#include <iostream>
#include <functional>

int main() {
    // бинарный функтор сложения
    std::plus<int> add; //вызывает x + y
    std::cout << "3 + 5 = " << add(3,5) << '\n';

    // бинарный функтор вычитания
    std::minus<int> sub; // вызывает x - y
    std::cout << "10 - 4 = " << sub(10,4) << '\n';

    // бинарный функтор умножения
    std::multiplies<int> mul; // вызывает x * y
    std::cout << "6 * 7 = " << mul(6,7) << '\n';

    // бинарный функтор деления
    std::divides<double> divd; // вызывает x / y
    std::cout << "9.0 / 2.0 = " << divd(9.0,2.0) << '\n';

    // бинарный функтор остатка
    std::modulus<int> mod; // вызывает x % y
    std::cout << "17 % 5 = " << mod(17,5) << '\n';

    // унарный функтор изменения знака
    std::negate<int> neg; // вызывает -x
    std::cout << "negate(7) = " << neg(7) << '\n';

    return 0;
}
