/*
Реализовать функцию, упаковывающую в 1 байт остатки от деления двух чисел на 8. (Использовать объединения и битовые поля структур).
*/

#include <iostream>
#include <bitset>

union Remains {
    struct {
        char remain1 : 4;
        char remain2 : 4;
    };
    char byte;    
};

int main() {
    int firstNumber = 5;
    int secondNumber = 8;

    Remains packed;
    packed.remain1 = firstNumber % 8;
    packed.remain2 = secondNumber % 8;

    std::bitset<4> bitsRemain1(packed.remain1);
    std::bitset<4> bitsRemain2(packed.remain2);
    std::bitset<8> bits(packed.byte);

    std::cout << bitsRemain1 << '\n' << bitsRemain2 << '\n' << bits << '\n';
    return 0;
}
