/*
Разработать структуру complex для представления комплексного числа.
Написать функции: ввода, вывода, сложения, умножения комплексных чисел.
*/

#include <iostream>

struct Complex {
    double real;     // Действительная часть
    double imag;     // Мнимая часть
};

// Ввод
void inputComplex(Complex &c) {
    std::cout << "Действительная часть: ";
    std::cin >> c.real;
    std::cout << "Мнимая часть: ";
    std::cin >> c.imag;
}

// Вывод
void outputComplex(const Complex &c) {
    std::cout << c.real;
    if (c.imag >= 0) std::cout << " + " << c.imag << "i";
    else std::cout << " - " << -c.imag << "i";
    std::cout << '\n';
}

// Сложение
Complex addComplex(const Complex &c1, const Complex &c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Умножение
Complex multiplyComplex(const Complex &c1, const Complex &c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    Complex c1, c2;
    std::cout << "Первое число." << '\n';
    inputComplex(c1);

    std::cout << "Второе число." << '\n';
    inputComplex(c2);

    Complex sum = addComplex(c1, c2);
    Complex product = multiplyComplex(c1, c2);

    std::cout << "Сумма: " << outputComplex(sum) << '\n';
    std::cout << "Произведение: " << outputComplex(product) << '\n';

    return 0;
}
