/*
Написать функцию с переменным числом параметров, которая выполняет сцепление строк (последний параметр 0).
*/

#include <iostream>
#include <stdarg.h>

std::string f(const char *first, ...) {
    std::string output;
    const char *str = first;

    va_list args;
    va_start(args, first);

    while (str != "0") {
        output += str;
        str = va_arg(args, const char*);
    }

    va_end(args);
    return output;
}

int main() {
    std::string result = f("Hello", " ", "world", "!", "0");
    std::cout << result << '\n';
}
