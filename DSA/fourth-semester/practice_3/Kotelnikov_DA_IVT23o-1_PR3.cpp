#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("tree.txt");
    unordered_map<string, pair<string, string>> inputMap; // <имя гнома, <сын, брат>>
    string line;

    // Формат строки: Имя;Сын;Брат
    while (getline(file, line)) {
        int pos1 = line.find(';'); // находим первую ;
        int pos2 = line.find(';', pos1 + 1); // находим вторую ;

        string name = line.substr(0, pos1); // имя гнома
        string firstChild = line.substr(pos1 + 1, pos2 - pos1 - 1); // имя сына
        string nextSibling = line.substr(pos2 + 1); // имя брата

        inputMap[name] = make_pair(firstChild, nextSibling);
    }
    file.close();

    unordered_map<string, vector<string>> tree; // <имя гнома, список его сыновей>

    // Строим дерево наследников
    for (const auto& pair : inputMap) { // проходим по списку гномов
        cout << pair.first << ": ";
        string name = pair.first; // имя гнома
        string child = inputMap[name].first; // получаем первого сына

        // Пока есть сын, добавляем его в список детей текущего гнома
        while (child != "") {
            tree[name].push_back(child); // добавляем сына
            child = inputMap[child].second; // переходим к следующему брату 
        }

        // Выводим всех сыновьёв текущего гнома
        for (const string& childName : tree[name]) {
            cout << childName << " ";
        }
        cout << "\n";
    }

    string child;
    cout << "Введите имя гнома для поиска его отца: ";
    cin >> child;

    string father = "";

    // Проходим по каждому элементу дерева: родитель и список его детей
    for (const auto& [parent, children] : tree) {

        // Проверяем, есть ли указанный сын в списке детей текущего родителя
        if (find(children.begin(), children.end(), child) != children.end()) {
            
            // Если нашли - сохраняем имя родителя как отца
            father = parent;
            break;
        }
    }

    if (!father.empty()) {
        cout << "Отец гнома " << child << ": " << father << '\n';
    } else {
        cout << "Отец не нашёлся" << '\n';
    }

    return 0;
}
