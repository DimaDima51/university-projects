/*
Написать рекурсивную функцию возведения вещественного числа t в целую степень M>=0.
*/

#include <iostream>

double power(double t, int M) {
    if (M == 0) return 1;
    return t * power(t, M - 1);
}

int main() {
    /*
    3.14 ^ 3
    1) 3.14 * 3.14^2    3) 3.14 * 3.14 * 3.14 * 1
    2) 3.14 * 3.14^1    2) 3.14 * 3.14 * 1
    3) 3.14 * 3.14^0    1) 3.14 * 1
    M = 0
    */

    double t;
    int M;

    std::cout << "Число t: ";
    std::cin >> t;
    std::cout << "Степень M: ";
    std::cin >> M;

    std::cout << t << "^" << M << " = " << power(t, M) << '\n';

    return 0;
}
