/*
������ ��� ������������ ����� ���� "���� �����" �� ����� C++.
�� ��������� ������������ ������������� ����, � ������� ��������� ������� ��������� ����� �� ������ ��������� � ������� �������, ����� �������� ���� � ������.

�������� ����������:
    ���� � ��������� ����: ������������ ������ ���������� �������, �� ����� � �������� ������� ��������� ���� (������, ������� ��� �������).
    �������� ��������: ������ ����� ������� ������� � �������� ��������� ���������� (�����, �������� �������, ����������� ������� ����� � �. �.).
    ��������� �����: ������ ������ �����, ����� �������� ���������� �����. ���� ����������� �� ��������� ��������� �����.
    ������ �������: ������� ����� �������� ������� � ������, ��������������� ��������, ��� ���� "����", ������� ����� ���� ���� �������� ����������.
    ��������� ����: ���� �����������, ����� ���� �� ���� ��������� ������� ����� �� �������.
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
    
    std::cout << "���� ����� �����. ����������, ������� ����� �������: ";
    int player_count; // ����� ������� � ����
    std::cin >> player_count;

    std::string * player_names = new std::string [player_count]; // ������ ��� �������
    int * player_points = new int [player_count]; // ������ �����

    std::cout << "- ������ �����! ������������, ��������� ���� � �������! � ����� �������-��� ����� �����! � ��� ������, ��� ������������ ����������� ����, � � ������������� ��������� � ������ �������. ������, � ������!\n\n";
    Sleep(1000);
    std::cout << "������� ����� �������:\n";
    for (int i = 0; i < player_count; i++) {
        std::cout << i + 1 << ") ";
        std::string player_name;
        std::cin >> player_name;
        player_names[i] = player_name;
        player_points[i] = 0; // ��������� �����
    }

    std::cout << "����� ������� �������.\n\n- ����, �� ��������� ����� �����: ";
    for (int i = 0; i < player_count; i++) {
        std::cout << player_names[i] << " ";
    }

    std::cout << "\n����������, �������� ��������� ���� (������� �����):\n1) ˸����\n2) �������\n3) ������\n���������: ";
    int gamemode = 0;

    while (gamemode < 1 || gamemode > 3) {  
        std::cin >> gamemode;
        if (gamemode < 1 || gamemode > 3) {
            std::cout << "������������ ����. ����������, ���������!\n���������: ";
        }
    }

    std::string words_eazy[] = {"����", "����", "����", "���", "����"};
    std::string quiz_eazy[] = {
        "������ �� ����, ��� ������ ����",
        "�������������� ������ ��� �����",
        "������� ����� ����",
        "����� � ��������� � ���������",
        "������ � �����, ����� �� ����������"
    };

    std::string words_normal[] = {"������", "�����", "��������", "������", "�������"};
    std::string quiz_normal[] = {
        "������, ������� ������ �� �����",
        "�������� ������������ �� �������",
        "���������� ��� ��������� � ��������",
        "������� �������� � �������",
        "�����, ��� ����� ���� � ������ �������"
    };

    std::string words_hard[] = {"���������", "��������", "�����������", "�����������", "��������"};
    std::string quiz_hard[] = {
        "����� ���� ����� ����� ���� � ������",
        "������� ����� �� �������",
        "����, ������� ����� �� ��������",
        "��, ��� ����� ��������",
        "������ ��� �������� ������"
    };

    std::string quiz;
    std::string correct_word;
    int number_question;

    switch (gamemode) {
        case 1:
            std::cout << "�� ������� ����� �����\n";
            number_question = rand() % (sizeof(quiz_eazy) / sizeof(*quiz_eazy));
            quiz = quiz_eazy[number_question];
            correct_word = words_eazy[number_question];
            break;
        case 2:
            std::cout << "�� ������� ������� �����\n";
            number_question = rand() % (sizeof(quiz_normal) / sizeof(*quiz_normal));
            quiz = quiz_normal[number_question];
            correct_word = words_normal[number_question];
            break;
        case 3:
            std::cout << "�� ������� ������ �����\n";
            number_question = rand() % (sizeof(quiz_hard) / sizeof(*quiz_hard));
            quiz = quiz_hard[number_question];
            correct_word = words_hard[number_question];
            break;
    }

    std::string answer(correct_word.length(), '_');
    std::cout << "��� � �������: " << quiz << '\n';
    std::cout << answer << '\n';
    
    while (true) {
        for (int i = 0; i < player_count; i++) {

            if (player_points[i] < 0) continue; // ����� �����

            std::string host_phrase[] = {"�������� �������!", "���, ������ ������� �������?", "���� ������� �� ��������?"};

            std::cout << player_names[i] << "! " << host_phrase[rand() % (sizeof(host_phrase) / sizeof(*host_phrase))] << '\n';
            Sleep(1000);

            std::string drum[] = {"350", "400", "450", "500", "600", "650", "700", "750", "800", "850", "950", "1000", "����", "����", "����"};
            
            std::string drumResult;
            drumResult = drum[rand() % (sizeof(drum) / sizeof(*drum))];

            // ������ ����
            if (drumResult == "����") {
                std::cout << "������ ����� �� ��������! ���� �������?\n������, ���� �� �������� ����, �� ����� � ���, ��� ��� �����!\n1) ����� ����\n2) �� ����� ����\n����� (������� �����): ";
                int choose = 0;
                while (choose < 1 || choose > 2) {  
                    std::cin >> choose;
                    if (choose < 1 || choose > 2) {
                        std::cout << "������������ ����. ����������, ���������!\n����� (������� �����): ";
                    }
                }

                std::string prizeMass[] = {"�-�-����������!", "�����!", "��� �� ����� 10000$!", "����� �����", "���������� �������", "�������!"};

                std::string prize;
                prize = prizeMass[rand() % (sizeof(prizeMass) / sizeof(*prizeMass))];
                
                switch (choose) {
                    case 1:
                        std::cout << "�� ���������� ����, � �� ���������... " << '\n';
                        Sleep(1000);
                        std::cout << prize << "\n�������, " << player_names[i] << ", �� ������� � ���� ����� �����!\n";
                        player_points[i] *= -1; // �.�. �����
                        break;
                    case 2:
                        std::cout << "���-��, ��� ���� �������, " << player_names[i] << ". �� � ��������, �� ���� �� ����������!\n�� ����� ��������... " << '\n';
                        Sleep(1000);
                        std::cout << prize << "\n";
                        break;
                }
            } else if (drumResult == "����") {
                std::cout << "������ ����� �� ��������! ����� ����� ������ �������?\n����� (������� ����� �����): ";
                int choose = 0;

                while (choose < 1 || choose > correct_word.length()) {  
                    std::cin >> choose;
                    if (choose < 1 || choose > correct_word.length()) {
                        std::cout << "������������ ����. ����������, ���������!\n����� (������� ����� �����): ";
                    }
                }
                answer[choose-1] = correct_word[choose-1];
                std::cout << "�� ������� ����� " << correct_word[choose-1] << "!\n";

            } else if (drumResult == "����") {
                std::cout << "������ ������ �� ��������! ������ �����������?\n�� ������ ���������� � �������� 2000 �����! (��� ����� ������� ����)\n����: ";
                int box_number;
                std::cin >> box_number;

                while (box_number < 0 || box_number > 6) {
                    std::cout << "������������ ����� �������. �������� ����� ������� (1-6) ��� ���������� (0): ";
                    std::cin >> box_number;
                }

                int key_box = rand() % 6 + 1;

                if (box_number == 0) {
                    std::cout << "������, ��� ���� ����, �� ��������� 2000 �����, � ���� ����� �������� ���������� ;)\n";
                    player_points[i] += 2000;
                }
                else if (box_number == key_box) {
                    std::cout << "�����������! �� ����� ����� � �������� ����������!\n";
                    player_points[i] *= -1; // ����� "�����"
                } else {
                    std::cout << "� ���������, ����� ���� � ������� ����� " << key_box << ". ���� ������������.\n";
                }

            } else {
                int amount = atoi(drumResult.c_str());
                std::cout << "��� �������� ������ �� " << amount << " ������!\n������� �����: ";

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
                    std::cout << "���������! �� ��������� " << amount * koef << " ������!\n";
                } else {    
                    std::cout << "�����������!\n";
                }
                
            }
            Sleep(1000);
            std::cout << '\n' << answer << '\n';

            if (answer == correct_word) {
                std::cout << "�����������! ����� " << player_names[i] << " ������ �����: " << correct_word << "\n�����:\n";

                for (int i = 0; i < player_count; i++) {
                    std::string left = player_points[i] < 0 ? " (�����)": "";
                    std::cout << i+1 << ") " << player_names[i] << ": " << fabs(player_points[i]) << left << '\n';
                }
                
                std::cout << "- ��, ��� �����, �� � ����� �� �����, �� ��������� ��� ������������ ��������. ����� ��� � ���������, ������ � ����. � ��, ���������, ���������!\n";
                return 0;
            }
        }
    }
}