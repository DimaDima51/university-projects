/*
Написать программу, которая вычисляет число ПИ с заданной точностью.
*/

#include <cmath>
#include <iostream>

int main() {
    int numb;
    double result = 0;

    std::cout << "Введите кол-во знаков после запятой: ";
    std::cin >> numb;

    unsigned int iter = pow(10, numb + 1); // точность ε
    std::cout.precision(numb + 1);

    // π по ряду Лейбница: π/4 = 1 - 1/3 + 1/5 - 1/7 + ...
    for (int i = 0; i < iter; i++) {
        // (-1)^i для чередования знаков
        result += pow(-1, i) / (2 * i + 1);
    }
    // 3,1415926
    std::cout << "π = " << result * 4;
}
