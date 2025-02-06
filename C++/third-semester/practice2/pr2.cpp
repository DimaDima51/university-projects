/*
Данный код представляет собой игру "Поле чудес" на языке C++.
Он имитирует классическую телевизионную игру, в которой несколько игроков угадывают слова на основе подсказок и вращают барабан, чтобы получить очки и бонусы.

Основной функционал:
    Ввод и настройка игры: Пользователь вводит количество игроков, их имена и выбирает уровень сложности игры (легкий, средний или тяжелый).
    Вращение барабана: Каждый игрок вращает барабан и получает различные результаты (баллы, бонусные сектора, возможность угадать букву и т. д.).
    Угаданные буквы: Игроки вводят буквы, чтобы отгадать загаданное слово. Очки начисляются за правильно угаданные буквы.
    Особые секторы: Барабан может показать сектора с призом, дополнительными бонусами, или даже "ключ", который может дать шанс выиграть автомобиль.
    Окончание игры: Игра завершается, когда одно из слов полностью угадано одним из игроков.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <cstring>
#include <math.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));
    
    std::cout << "Игра «Поле чудес». Пожалуйста, введите число игроков: ";
    int player_count; // Число игроков в игре
    std::cin >> player_count;

    std::string * player_names = new std::string [player_count]; // Массив имён игроков
    int * player_points = new int [player_count]; // Массив очков

    std::cout << "- Добрый вечер! Здравствуйте, уважаемые дамы и господа! В эфире капитал-шоу «Поле чудес»! И как обычно, под аплодисменты зрительного зала, я с удовольствием приглашаю в студию игроков. Игроки, в студию!\n\n";
    Sleep(1000);
    std::cout << "Введите имена игроков:\n";
    for (int i = 0; i < player_count; i++) {
        std::cout << i + 1 << ") ";
        std::string player_name;
        std::cin >> player_name;
        player_names[i] = player_name;
        player_points[i] = 0; // Обнуление очков
    }

    std::cout << "Имена успешно введены.\n\n- Итак, за барабаном «Поля чудес»: ";
    for (int i = 0; i < player_count; i++) {
        std::cout << player_names[i] << " ";
    }

    std::cout << "\nПожалуйста, выберите сложность игры (введите номер):\n1) Лёгкая\n2) Средняя\n3) Тяжёлая\nСложность: ";
    int gamemode = 0;

    while (gamemode < 1 || gamemode > 3) {  
        std::cin >> gamemode;
        if (gamemode < 1 || gamemode > 3) {
            std::cout << "Некорректный ввод. Пожалуйста, повторите!\nСложность: ";
        }
    }

    std::string words_eazy[] = {"ВОЛК", "КРУГ", "МОСТ", "ЛЕС", "ЗОНТ"};
    std::string quiz_eazy[] = {
        "Хищник из леса, его боятся овцы",
        "Геометрическая фигура без углов",
        "Переход через реку",
        "Место с деревьями и животными",
        "Носишь в дождь, чтобы не промокнуть"
    };

    std::string words_normal[] = {"КОМПАС", "ПОЕЗД", "КАРАНДАШ", "ТЮЛЕНЬ", "КОФЕЙНЯ"};
    std::string quiz_normal[] = {
        "Прибор, который укажет на север",
        "Средство передвижения по рельсам",
        "Инструмент для рисования и черчения",
        "Морское животное с ластами",
        "Место, где варят кофе и подают напитки"
    };

    std::string words_hard[] = {"СОСЕДСТВО", "ПАЛЬМИРА", "ОСТРОВИТЯНЕ", "ПЕРЕМЕНЧИВО", "МИКРОФОН"};
    std::string quiz_hard[] = {
        "Когда люди живут рядом друг с другом",
        "Древний город на востоке",
        "Люди, которые живут на островах",
        "То, что часто меняется",
        "Прибор для усиления голоса"
    };

    std::string quiz;
    std::string correct_word;
    int number_question;

    switch (gamemode) {
        case 1:
            std::cout << "Вы выбрали лёгкий режим\n";
            number_question = rand() % (sizeof(quiz_eazy) / sizeof(*quiz_eazy));
            quiz = quiz_eazy[number_question];
            correct_word = words_eazy[number_question];
            break;
        case 2:
            std::cout << "Вы выбрали средний режим\n";
            number_question = rand() % (sizeof(quiz_normal) / sizeof(*quiz_normal));
            quiz = quiz_normal[number_question];
            correct_word = words_normal[number_question];
            break;
        case 3:
            std::cout << "Вы выбрали тяжёлый режим\n";
            number_question = rand() % (sizeof(quiz_hard) / sizeof(*quiz_hard));
            quiz = quiz_hard[number_question];
            correct_word = words_hard[number_question];
            break;
    }

    std::string answer(correct_word.length(), '_');
    std::cout << "Вот и загадка: " << quiz << '\n';
    std::cout << answer << '\n';
    
    while (true) {
        for (int i = 0; i < player_count; i++) {

            if (player_points[i] < 0) continue; // Игрок выбыл

            std::string host_phrase[] = {"Вращайте барабан!", "Что, будете барабан вращать?", "Чего барабан не вращаете?"};

            std::cout << player_names[i] << "! " << host_phrase[rand() % (sizeof(host_phrase) / sizeof(*host_phrase))] << '\n';
            Sleep(1000);

            std::string drum[] = {"350", "400", "450", "500", "600", "650", "700", "750", "800", "850", "950", "1000", "ПРИЗ", "ПЛЮС", "КЛЮЧ"};
            
            std::string drumResult;
            drumResult = drum[rand() % (sizeof(drum) / sizeof(*drum))];

            // СЕКТОР ПРИЗ
            if (drumResult == "ПРИЗ") {
                std::cout << "Сектор «Приз» на барабане! Ваше решение?\nЗнайте, если вы выберете ящик, то уйдёте с тем, что там лежит!\n1) Взять приз\n2) Не брать приз\nВыбор (введите номер): ";
                int choose = 0;
                while (choose < 1 || choose > 2) {  
                    std::cin >> choose;
                    if (choose < 1 || choose > 2) {
                        std::cout << "Некорректный ввод. Пожалуйста, повторите!\nВыбор (введите номер): ";
                    }
                }

                std::string prizeMass[] = {"А-А-АВТОМОБИЛЬ!", "Плеер!", "Чек на целых 10000$!", "Целую тыкву", "Игрушечную машинку", "Тапочки!"};

                std::string prize;
                prize = prizeMass[rand() % (sizeof(prizeMass) / sizeof(*prizeMass))];
                
                switch (choose) {
                    case 1:
                        std::cout << "Вы открываете ящик, и вы получаете... " << '\n';
                        Sleep(1000);
                        std::cout << prize << "\nСпасибо, " << player_names[i] << ", за участие в игре «Поле чудес»!\n";
                        player_points[i] *= -1; // Т.е. выбыл
                        break;
                    case 2:
                        std::cout << "Что-же, это ваше решение, " << player_names[i] << ". Но я посмотрю, от чего вы отказались!\nВы могли получить... " << '\n';
                        Sleep(1000);
                        std::cout << prize << "\n";
                        break;
                }
            } else if (drumResult == "ПЛЮС") {
                std::cout << "Сектор «Плюс» на барабане! Какую букву хотите открыть?\nВыбор (введите номер буквы): ";
                int choose = 0;

                while (choose < 1 || choose > correct_word.length()) {  
                    std::cin >> choose;
                    if (choose < 1 || choose > correct_word.length()) {
                        std::cout << "Некорректный ввод. Пожалуйста, повторите!\nВыбор (введите номер буквы): ";
                    }
                }
                answer[choose-1] = correct_word[choose-1];
                std::cout << "Вы открыли букву " << correct_word[choose-1] << "!\n";

            } else if (drumResult == "КЛЮЧ") {
                std::cout << "Сектор «Ключ» на барабане! Хотите попробовать?\nВы можете отказаться и получить 2000 очков! (Для этого введите ноль)\nВвод: ";
                int box_number;
                std::cin >> box_number;

                while (box_number < 0 || box_number > 6) {
                    std::cout << "Некорректный номер коробки. Выберите номер коробки (1-6) или откажитесь (0): ";
                    std::cin >> box_number;
                }

                int key_box = rand() % 6 + 1;

                if (box_number == 0) {
                    std::cout << "Хорошо, это ваше дело, вы получаете 2000 очков, а хотя могли получить автомобиль ;)\n";
                    player_points[i] += 2000;
                }
                else if (box_number == key_box) {
                    std::cout << "Поздравляем! Вы нашли ключи и выиграли автомобиль!\n";
                    player_points[i] *= -1; // Игрок "выбыл"
                } else {
                    std::cout << "К сожалению, ключи были в коробке номер " << key_box << ". Игра продолжается.\n";
                }

            } else {
                int amount = atoi(drumResult.c_str());
                std::cout << "Вам выпадает сектор на " << amount << " баллов!\nВведите букву: ";

                char bukva;
                std::cin >> bukva;
                bukva = toupper(bukva);

                if (correct_word.find(bukva) != std::string::npos) {
                    int koef = 0;
                    for (int j = 0; j < correct_word.length(); j++) {
                        if (correct_word[j] == bukva && answer[j] == '_') {
                            answer[j] = bukva;
                            koef += 1;
                        }
                    }
                    player_points[i] += amount * koef; 
                    std::cout << "Правильно! Вы получаете " << amount * koef << " баллов!\n";
                } else {    
                    std::cout << "Неправильно!\n";
                }
                
            }
            Sleep(1000);
            std::cout << '\n' << answer << '\n';

            if (answer == correct_word) {
                std::cout << "Поздравляем! Игрок " << player_names[i] << " угадал слово: " << correct_word << "\nИтоги:\n";

                for (int i = 0; i < player_count; i++) {
                    std::string left = player_points[i] < 0 ? " (Выбыл)": "";
                    std::cout << i+1 << ") " << player_names[i] << ": " << fabs(player_points[i]) << left << '\n';
                }
                
                std::cout << "- Те, кто играл, но в финал не вышел, вы получаете мои эксклюзивные кружечки. Таких нет в магазинах, только у меня. А вы, финалисты, завидуйте!\n";
                return 0;
            }
        }
    }
}