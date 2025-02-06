/*
Разработать структуру rac для представления рациональных чисел.
Написать функции: деления и сокращения рациональных чисел.
*/

#include <iostream>
#include <numeric>

struct Rac {
    int numerator;   // Числитель
    int denominator; // Знаменатель
};

Rac divide(const Rac &r1, const Rac &r2) {
    return Rac{r1.numerator * r2.denominator, r1.denominator * r2.numerator};
}

Rac simplify(const Rac r) {
    int gcd = std::gcd(r.numerator, r.denominator);
    int num = r.numerator / gcd;
    int den = r.denominator / gcd;
    return Rac{num, den};
}

int main() {
    // 9841/321 : 99/8 = 78728/31779
    // 3/8 : 4/9 = 27/32
    Rac r1 = {3, 8};
    Rac r2 = {4, 9};

    // Сокращаем r1 и r2
    r1 = simplify(r1);
    r2 = simplify(r2);

    std::cout << "r1 = " << r1.numerator << "/" << r1.denominator << '\n';
    std::cout << "r2 = " << r2.numerator << "/" << r2.denominator << '\n';
    
    Rac r3 = simplify(divide(r1, r2));

    std::cout << "r3 = " << r3.numerator << "/" << r3.denominator << '\n';

    return 0;
}
