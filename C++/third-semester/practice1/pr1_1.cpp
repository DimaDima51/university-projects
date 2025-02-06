/*
Написать программу перевода числа в денежный формат:
Пользователь вводит число от 1 до 999. Необходимо добавить слово: рубль, рублей, рубля.
*/

#include <iostream>

int main(){
    int number;
    while (1){
        std::cout << "Введите число от 1 до 999: ";
        std::cin >> number;
        
        if (number > 999 || number < 0) {
            std::cout << "Ваше число вне диапазона, повторите попытку!\n"; 
            continue;
        }

        std::cout << "Вы ввели " << number;
        switch (number % 10) {
            case 0:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9: std::cout << " рублей\n";
            break;

            case 1: std::cout << " рубль\n";
            break;

            case 2:
            case 3:
            case 4: std::cout << " рубля\n";
            break;
            
            default: std::cout << "Не корректный ввод, повторите попытку!\n"; break;
        }
    }

    return 0;
}