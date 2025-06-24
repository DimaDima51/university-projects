#ifndef MYGAUSS_H
#define MYGAUSS_H

#include <iostream>
#include <math.h>

class MyGauss {
    public:
        MyGauss() {
            std::cout << "n = ";
            std::cin >> n;
            mk = new double* [n];
            x = new double[n];
            b = new double[n];
            for (int i = 0; i < n; i++)
                mk[i] = new double [n];

            std::cout << "Коэффициенты" << '\n';
            
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    std::cout << "mk[" << i << "][" << j << "] = ";
                    std::cin >> mk[i][j];
                }

            std::cout << "Вектора" << '\n';
            
            for (int i = 0; i < n; i++) {
                std::cout << "b[" << i << "] = ";
                std::cin >> b[i];
            }
        }

        // Конструктор копирования (глубокое копирование)
        MyGauss(const MyGauss& other) : n(other.n) {
            mk = new double*[n];
            b = new double[n];
            x = new double[n];
            for (int i = 0; i < n; i++) {
                mk[i] = new double[n];
                for (int j = 0; j < n; j++) {
                    mk[i][j] = other.mk[i][j];
                }
                b[i] = other.b[i];
                x[i] = other.x[i];
            }
        }

        // Перегрузка оператора присваивания (глубокое копирование)
        MyGauss& operator=(const MyGauss& other) {
            if (this == &other) // Проверка на самоприсваивание
                return *this;

            for (int i = 0; i < n; i++)
                delete[] mk[i];
            delete[] mk;
            delete[] b;
            delete[] x;

            // Копируем данные из other
            n = other.n;
            mk = new double*[n];
            b = new double[n];
            x = new double[n];
            for (int i = 0; i < n; i++) {
                mk[i] = new double[n];
                for (int j = 0; j < n; j++) {
                    mk[i][j] = other.mk[i][j];
                }
                b[i] = other.b[i];
                x[i] = other.x[i];
            }

            return *this;
        }

        ~MyGauss() {
            int i;
            delete []b;
            delete []x;
            for (i = 0; i < n; i++)
                delete [] mk[i];
            delete []mk;
        }

        void SolveSystem() {
            for (int k = 0; k < n; k++) {
                // Поиск главного элемента
                int maxRow = k;
                for (int i = k + 1; i < n; i++) {
                    if (std::fabs(mk[i][k]) > std::fabs(mk[maxRow][k])) {
                        maxRow = i;
                    }
                }
    
                // Перестановка строк
                if (maxRow != k) {
                    std::swap(mk[k], mk[maxRow]);
                    std::swap(b[k], b[maxRow]);
                }
    
                // Прямой ход метода Гаусса
                for (int i = k + 1; i < n; i++) {
                    double factor = mk[i][k] / mk[k][k];
                    for (int j = k; j < n; j++) {
                        mk[i][j] -= factor * mk[k][j];
                    }
                    b[i] -= factor * b[k];
                }
            }
    
            // Обратный ход (вычисление неизвестных)
            for (int i = n - 1; i >= 0; i--) {
                x[i] = b[i];
                for (int j = i + 1; j < n; j++) {
                    x[i] -= mk[i][j] * x[j];
                }
                x[i] /= mk[i][i];
            }
        }

        void print_result() {
            std::cout << "Результат" << '\n';
            for (int i = 0; i < n; i++)
                std::cout << "x[" << i << "] = " << x[i] << '\n';
        }

        friend std::ostream& operator<<(std::ostream& t, const MyGauss& obj) {
            t << "Исходная расширенная матрица:\n";
            for (int i = 0; i < obj.n; i++) {
                for (int j = 0; j < obj.n; j++)
                    t << obj.mk[i][j] << " ";
                t << obj.b[i] << '\n';
            }
            return t;
        }

    private:
        int n; // Размерность матрицы
        double **mk; // Матрица коэффицентов
        double *b; // Вектор правых частей
        double *x; // Результат
};

#endif // MYGAUSS_H