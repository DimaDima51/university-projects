#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

// Чтение графа из файла в виде списков смежности
vector<vector<int>> readGraph(const string &filename, int &vertexNum) {
    ifstream file(filename);    // открываем файл для чтения
    vector<vector<int>> list;   // список смежности
    string line;
    vertexNum = 0;  // количество вершин
    
    // Читаем файл построчно
    while (getline(file, line)) {
        vector<int> neighbors;  // вектор соседей для текущей вершины
        int vertex;
        stringstream ss(line);  // поток для разбора строки
        
        // Считываем все номера соседних вершин из строки
        while (ss >> vertex) {
            neighbors.push_back(vertex);
        }
        
        list.push_back(neighbors);  // добавляем список соседей
        vertexNum++;    // увеличиваем число вершин
    }
    file.close();
    return list;    // возвращаем считанный список смежности
}

// Создание матрицы смежности из списка смежности
// list - список смежности, vertexNum - количество вершин
vector<vector<int>> createMatrix(const vector<vector<int>> &list, int vertexNum) {
    // Инициализируем квадратную матрицу нулей
    vector<vector<int>> matrix(vertexNum, vector<int>(vertexNum, 0));
    
    // Проходим по каждой вершине и её списку соседей
    for (int i = 0; i < list.size(); ++i) {
        for (int j = 0; j < list[i].size(); ++j) {
            int neighbor = list[i][j];
            matrix[i][neighbor] = 1; // ставим 1, если есть ребро i -> neighbor
        }
    }
    return matrix;
}

// Подсчёт числа рёбер в неориентированном графе по матрице смежности
// Считаем только верхний треугольник (включая диагональ)
int countEdges(const vector<vector<int>> &matrix) {
    int edges = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 1) {
                edges++;
            }
        }
    }
    return edges;
}

// Поиск изолированных вершин (вершины без рёбер)
vector<int> findIsolated(const vector<vector<int>> &matrix) {
    vector<int> isolated;
    for (int i = 0; i < matrix.size(); ++i) {
        bool isIsolated = true; // предполагаем, что вершина изолирована
        int j = 0;
        // Проверяем все рёбра, пока не найдём хотя бы одно (isIsolated = false)
        while (j < matrix[i].size() && isIsolated) {
            if (matrix[i][j] == 1) {
                isIsolated = false; // найдено ребро -> вершина не изолирована
            }
            j++;
        }
        if (isIsolated) {
            isolated.push_back(i);
        }
    }
    return isolated;
}

// Поиск петель в графе (рёбер вида v -> v)
vector<int> findLoops(const vector<vector<int>> &matrix) {
    vector<int> loops;
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] == 1) { // проверяем диагональный элемент
            loops.push_back(i);
        }
    }
    return loops;
}

// Расчёт степеней вершин по матрице смежности
// Степень = количество единиц в строке
map<int, int> calculateDegrees(const vector<vector<int>> &matrix) {
    map<int, int> degrees;
    for (int i = 0; i < matrix.size(); ++i) {
        int degree = 0;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 1) {
                degree++;
            }
        }
        degrees[i] = degree; // сохраняем степень для вершины i
    }
    return degrees;
}

// Запись матрицы смежности в конец файла
void writeMatrix(const string &filename, const vector<vector<int>> &matrix) {
    ofstream file(filename, ios::app); // открываем в режиме добавления
    file << "\nМатрица смежности:\n";
    for (const auto &neighbors : matrix) {
        for (int val : neighbors) {
            file << val << ' ';
        }
        file << '\n';
    }
    file.close();
}

int main() {
    string filename = "input.txt";
    int vertexNum; // число вершин

    // Читаем граф и получаем смежности и число вершин
    vector<vector<int>> list = readGraph(filename, vertexNum);
    // Создаём из списка смежности матрицу
    vector<vector<int>> matrix = createMatrix(list, vertexNum);

    int edgeNum = countEdges(matrix);   // число рёбер
    vector<int> isolated = findIsolated(matrix);    // изолированные вершины
    vector<int> loops = findLoops(matrix);  // петли
    map<int, int> degrees = calculateDegrees(matrix);   // степени вершин

    cout << "Количество вершин: " << vertexNum << '\n';
    cout << "Количество ребер: " << edgeNum << '\n';

    cout << "Матрица смежности:" << '\n';
    for (const auto &neighbors : matrix) {
        for (int val : neighbors) {
            cout << val << ' ';
        }
        cout << '\n';
    }

    // Вывод информации об изолированных вершинах
    if (!isolated.empty()) {
        cout << "Изолированные вершины: ";
        for (int v : isolated) cout << v << ' ';
        cout << '\n';
    } else {
        cout << "Изолированные вершины отсутствуют." << '\n';
    }

    // Вывод информации о петлях
    if (!loops.empty()) {
        cout << "Петли: ";
        for (int v : loops) cout << v << ' ';
        cout << '\n';
    } else {
        cout << "Петли отсутствуют." << '\n';
    }

    // Сортируем и выводим степени вершин по убыванию
    cout << "Степени вершин:" << '\n';
    vector<pair<int, int>> sortedDegrees(degrees.begin(), degrees.end());
    sort(sortedDegrees.begin(), sortedDegrees.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return b.second < a.second; // сортировка по убыванию степени
    });
    for (const auto &p : sortedDegrees) {
        cout << p.first << ": " << p.second << '\n';
    }

    writeMatrix(filename, matrix);

    return 0;
}