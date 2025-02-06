/*
Реализовать вычисление интеграла функции с заданной точностью еps:
1. Методом левых прямоугольников
2. Методом правых прямоугольников
Использовать указатель на функцию.
Функция задаётся преподавателем индивидуально каждому студенту.
Отрезок [a; b] задаётся пользователем программы 
*/

#include <iostream>
#include <cmath>

double sample(double x) {
    return (15 * x + cos(x)) / (sqrt(x) + 12);
}

double leftRectangles(double (*func)(double), double a, double b, double eps) {
    double integral = 0.0, prev_integral;
    int n = 1;
    double h;

    do {
        prev_integral = integral;
        integral = 0.0;
        h = (b - a) / n;

        // Сумма от i = 0 до n-1 функции f(xi)
        for (int i = 0; i < n; ++i) {
            integral += func(a + i * h) * h;
        }

        n *= 2;
    } while (fabs(integral - prev_integral) > eps);

    return integral;
}

double rightRectangles(double (*func)(double), double a, double b, double eps) {
    double integral = 0.0, prev_integral;
    int n = 1;
    double h;

    do {
        prev_integral = integral;
        integral = 0.0;
        h = (b - a) / n;

        // Сумма от i = 1 до n функции f(xi)
        for (int i = 1; i <= n; ++i) {
            integral += func(a + i * h) * h;
        }

        n *= 2;
    } while (fabs(integral - prev_integral) > eps);

    return integral;
}

int main() {

    /*
        [0; 2] с точностью 0.001:
            ЛП 2.356865
            ПП 2.357714

        [0; 5] с точностью 0.000001:
            ЛП 38.108361
            ПП 38.108361
    */

    double a, b, eps;

    std::cout << "Введите левую границу интегрирования (a): ";
    std::cin >> a;
    std::cout << "Введите правую границу интегрирования (b): ";
    std::cin >> b;
    std::cout << "Введите точность eps: ";
    std::cin >> eps;
    
    double (*methodRectangle)(double (*)(double), double, double, double);

    methodRectangle = leftRectangles;
    double resultLeft = methodRectangle(sample, a, b, eps);

    methodRectangle = rightRectangles;
    double resultRight = methodRectangle(sample, a, b, eps);


    //double resultLeft = leftRectangles(sample, a, b, eps);
    //double resultRight = rightRectangles(sample, a, b, eps);
    

    std::cout << "Интеграл методом левых прямоугольников: " << resultLeft << '\n';
    std::cout << "Интеграл методом правых прямоугольников: " << resultRight << '\n';

    return 0;
}
