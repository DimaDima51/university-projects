/*
Написать функцию для перевода числа ЛЮБОГО типа в строку символов(использовать бестиповый указатель).
*/

#include <iostream>
#include <string>
#include <typeinfo>

std::string toString(void *ptr, const std::type_info& type) {
    std::string output;

    if (type == typeid(int)) {
        output = std::to_string(*static_cast<int*>(ptr));
    } else if (type == typeid(double)) {
        output = std::to_string(*static_cast<double*>(ptr));
    } else if (type == typeid(float)) {
        output = std::to_string(*static_cast<float*>(ptr));
    } else if (type == typeid(char)) {
        output = std::string(1, *static_cast<char*>(ptr));
    } else {
        output = "Ошибка";
    }

    return output;
}

int main() {
    int a = 1;
    double b = 2.3;
    float c = 4.5;
    char d = 'A';

    std::cout << toString(&a, typeid(a)) << '\n';
    std::cout << toString(&b, typeid(b)) << '\n';
    std::cout << toString(&c, typeid(c)) << '\n';
    std::cout << toString(&d, typeid(d)) << '\n';

}
