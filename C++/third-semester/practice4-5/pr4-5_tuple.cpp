/*
Посмотреть что такое tuple, написать пример использования tuple
*/

#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, std::string, double> modifyTuple(std::tuple<int, std::string, double> t, int number, std::string phrase, double pointNumber) {
    std::get<0>(t) = number;
    std::get<1>(t) = phrase;
    std::get<2>(t) = pointNumber;
    return t;
}

int main() {
    std::tuple<int, std::string, double> myTuple = std::make_tuple(42, "Привет", 3.14);

    std::cout << "\t Исходный кортеж:\n";
    std::cout << "Число: " << std::get<0>(myTuple) << '\n';
    std::cout << "Текст: " << std::get<1>(myTuple) << '\n';
    std::cout << "Число double: "<< std::get<2>(myTuple) << '\n';

    myTuple = modifyTuple(myTuple, 52, "Привет, мир!", 2.718);

    std::cout << "\t Новый кортеж после изменения:\n";
    std::cout << "Число: " << std::get<0>(myTuple) << '\n';
    std::cout << "Текст: " << std::get<1>(myTuple) << '\n';
    std::cout << "Число double: "<< std::get<2>(myTuple) << '\n';

    return 0;
}
