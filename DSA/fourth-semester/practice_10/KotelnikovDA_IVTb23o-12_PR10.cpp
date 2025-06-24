#include <cmath>
#include <iomanip>  // для setprecision
#include <iostream>
#include <limits>  // для numeric_limits
#include <vector>

using namespace std;

// Структура для представления точки на плоскости
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// Евклидово расстояние между двумя точками
double distance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// Вычисляет минимальную суммарную длину ВСЕХ хорд при триангуляции
// выпуклого n-угольника.
// polygon — вектор точек, заданных по часовой стрелке.
double minTriangulationCost(const vector<Point>& polygon) {
    int n = polygon.size();
    if (n < 3) return 0.0;  // триангуляция невозможна

    // dp[i][j] — оптимальная стоимость триангуляции части
    // полигональной цепочки от i до j (включительно)
    vector<vector<double>> dp(n, vector<double>(n, 0.0));

    // Для всех пар i<j с gap<2 dp[i][j]=0 (некорректные или тривиальные интервалы)

    // Разворачиваем «окно» от длины 2 вверх до n-1
    for (int gap = 2; gap < n; ++gap) {
        for (int i = 0; i + gap < n; ++i) {
            int j = i + gap;

            dp[i][j] = 99999.9;

            // Перебираем возможную точку k для последнего треугольника (i,k,j)
            for (int k = i + 1; k < j; ++k) {
                // стоимость левой части + правой части
                double cost = dp[i][k] + dp[k][j];

                // добавляем длины хорд (i,k) и (k,j), если они действительно хорды:
                // если k != i+1, значит i–k не ребро исходного многоугольника, а хорда
                if (k != i + 1) {
                    cost += distance(polygon[i], polygon[k]);
                }
                // аналогично для k–j
                if (k != j - 1) {
                    cost += distance(polygon[k], polygon[j]);
                }

                // поддерживаем минимум
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // Ответ — триангуляция всего многоугольника
    return dp[0][n - 1];
}

int main() {

    int numPoints;
    cout << "Введите количество вершин многоугольника: ";
    cin >> numPoints;

    if (numPoints < 3) {
        cerr << "Ошибка: многоугольник должен иметь минимум 3 вершины.\n";
        return 1;
    }

    vector<Point> polygon;
    polygon.reserve(numPoints);

    cout << "Введите координаты вершин по часовой стрелке (x y):\n";
    for (int i = 0; i < numPoints; ++i) {
        double x, y;
        cin >> x >> y;
        polygon.emplace_back(x, y);
    }

    double result = minTriangulationCost(polygon);

    // Вывод с двумя знаками после запятой
    cout << "Минимальная суммарная длина хорд: " << result << "\n";

    return 0;
}
