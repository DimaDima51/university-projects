/*
Написать рекурсивную функцию для вычисления длины строки.
*/

#include <iostream>

int stringLength(const char *str) {
    if (*str == '\0') {
        return 0;
    } else {
        // 1 - текущий символ
        return 1 + stringLength(str + 1);
    }
}

int main() {
    const char *primer = "text";
    std::cout << "Длина строки: " << stringLength(primer) << '\n';
}
