/*
Написать программу, которая выводит дату следующего дня.
Пользователю необходимо задать текущую дату.
*/

#include <iostream>

int main(){
    int day, month, year;

    std::cout << "Введите день: ";
    std::cin >> day;
    std::cout << "Введите месяц: ";
    std::cin >> month;
    std::cout << "Введите год: ";
    std::cin >> year;

    // Проверка корректности ввода года
    if (year < 0) {
        std::cout << "Ошибка! Год не может быть отрицательным.\n";
        return 1;
    }

    // Проверка корректности ввода месяца
    if (month < 1 || month > 12) {
        std::cout << "Ошибка! Месяц должен быть в диапазоне от 1 до 12.\n";
        return 1;
    }

    int daysInMonth; // дней в месяце 
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        // январь март май июль авгус октябрь декабрь
        daysInMonth = 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        // апрель июнь сентябрь ноябрь
        daysInMonth = 30;
    } else if (month == 2) {
        // февраль
        // если год кратен 4, но не кратен 100 или год кратен 400
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29; // год високосный, поэтому в феврале +1 день
        } else daysInMonth = 28;
    }

    // Проверка корректности ввода дня
    if (day < 1 || day > daysInMonth) {
        std::cout << "Ошибка! День должен быть в диапазоне от 1 до " << daysInMonth << " для указанного месяца.\n";
        return 1;
    }    

    day++;

    // наступил новый месяц
    if (day > daysInMonth) {
        day = 1;
        month++;
    }

    // наступил новый год
    if (month > 12) {
        month = 1;
        year++;
    }

    std::cout << "Следующая дата: " << day << "." << month << "." << year << "\n";


    return 0;
}