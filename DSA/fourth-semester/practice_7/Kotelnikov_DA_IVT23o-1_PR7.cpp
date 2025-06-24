#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

int main() {
    std::ifstream fin("input.txt");

    // adj - список смежности: для каждой дисциплины хранится вектор дисциплин, зависящих от неё
    // indegree - количество входящих рёбер (требований) для каждой дисциплины
    std::map<std::string, std::vector<std::string>> adj;
    std::map<std::string, int> indegree;
    std::set<std::string> allCourses;

    // Читаем пары "предшественник - последователь"
    std::string line;
    while (std::getline(fin, line)) {
        int dashPos = line.find(" - ");

        std::string first = line.substr(0, dashPos);    // Предшественник
        std::string second = line.substr(dashPos + 3);  // Последователь

        adj[first].push_back(second);
        // Увеличим indegree у second
        indegree[second]++;
        // Зарегистрируем обе дисциплины в множестве всех курсов
        allCourses.insert(first);
        allCourses.insert(second);
        // Если ещё нет записи в indegree, создаём с нулём
        if (indegree.find(first) == indegree.end()) {
            indegree[first] = 0;
        }
    }
    fin.close();

    // Вывод списка всех дисциплин
    std::cout << "Список всех дисциплин (" << allCourses.size() << "):\n";
    for (const auto& course : allCourses) {
        std::cout << "  " << course << '\n';
    }
    std::cout << '\n';

    // Для каждой дисциплины - список поддерживаемых (зависящих)
    std::cout << "Список поддерживаемых дисциплин:\n";
    for (const auto& course : allCourses) {
        std::cout << course << ": ";

        // Проверяем, есть ли у дисциплины зависимые
        // adj.count(course) проверяет есть ли ключ в словаре adj
        // adj[course].empty() проверяет не пустой ли вектор
        if (adj.count(course) && !adj[course].empty()) {
            // Если есть зависимые дисциплины - они выводятся
            for (const auto& dep : adj[course]) {
                std::cout << dep << " ";
            }
        } else {
            std::cout << "(нет зависимых)";
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    // Сортировка
    std::queue<std::string> q;
    // Инициализируем очередь всеми вершинами с indegree == 0
    for (const auto& kv : indegree) {
        if (kv.second == 0) {
            q.push(kv.first);
        }
    }

    std::vector<std::string> topoOrder; // Вектор для хранения отсортированного списка

    // Пока есть дисциплины в очереди с нулевой входящей степенью
    while (!q.empty()) {
        std::string u = q.front();  // Берём из очереди дисциплину без незавершённых предшественников
        q.pop();                    // Удаляем её из очереди
        topoOrder.push_back(u);     // Добавляем эту дисциплину в вектор

        // Для каждой дисциплины, которая зависит от текущей (т.е. для каждого "потомка" u)
        for (const auto& v : adj[u]) {
            indegree[v]--;  // Уменьшаем количество её невыполненных предшественников (indegree)
            
            // Если у дисциплины v больше нет зависимостей (indegree == 0),
            // то она готова и её можно добавить в очередь для обработки
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Вывод упорядоченной последовательности
    std::cout << "Отсортированная последовательность:\n";
    for (int i = 0; i < topoOrder.size(); ++i) {
        std::cout << "  " << (i + 1) << ". " << topoOrder[i] << '\n';
    }

    return 0;
}
