/*
Написать программу проверки умения правильно складывать и вычитать числа (не превышающие 100).
Программа должна вывести 10 примеров. Придумать критерий оценки.
Вывести данный критерий в виде сообщения.
По результатам выставить пользователю соответствующую оценку.
*/

#include <iostream>
#include <ctime>

int main(){

    std::cout << "Программа проверки умения складывать и вычитать\nКритерий оценивания:\n 9-10 = 5\n 6-8 = 4\n 4-5 = 3\n 0-3 = 2\n\n";
    srand(time(NULL));

    int correct_answers = 0;
    for(int i = 1; i <= 10; i++){
        int is_summ = rand() % 2;
        int first_numb = rand() % 100 + 1;
        int second_numb = rand() % 100 + 1;
        int answer, correct_answer;
        char symb;
        
        if (is_summ) symb = '+';
        else symb = '-';

        std::cout << "№" << i << ") Сколько будет: " << first_numb << symb << second_numb << " ?\nОтвет: ";
        std::cin >> answer;

        correct_answer = is_summ ? first_numb+second_numb : first_numb-second_numb;

        if (answer == correct_answer) {
            std::cout << "Молодец!\n";
            correct_answers++;
        } else std::cout << "Неправильно! :(\n";

    }
    switch (correct_answers) {

        case 10:
        case 9: std::cout << "Оценка: 5"; break;
        
        case 8:
        case 7: 
        case 6: std::cout << "Оценка: 4"; break;

        case 5:
        case 4: 
        case 3: std::cout << "Оценка: 3"; break;

        case 2:
        case 1: 
        case 0: std::cout << "Оценка: 2"; break;

        default: break;
    }
    std::cout << " Правильных ответов: " << correct_answers << "\n";
    return 0;

}

