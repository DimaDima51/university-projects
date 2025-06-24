#include "matrix.h"
#include <QMessageBox>
#include <QTableWidget>
#include <cmath>

// Конструктор
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    if (rows < 0 || cols < 0) {
        throw NegativeSizeException();
    }
    allocateMemory();
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    allocateMemory();
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
}

// Деструктор
Matrix::~Matrix() {
    freeMemory();
}

// Выделение памяти
void Matrix::allocateMemory() {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new double[cols]();
}

// Освобождение памяти
void Matrix::freeMemory() {
    for (int i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}

// Перегруженные операторы доступа к элементам
double& Matrix::operator()(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw IndexOutOfBoundsException();
    }
    return data[row][col];
}

const double& Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw IndexOutOfBoundsException();
    }
    return data[row][col];
}

// Оператор присваивания
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    freeMemory();
    rows = other.rows;
    cols = other.cols;
    allocateMemory();
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    return *this;
}

// Оператор сложения
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

// Оператор вычитания
Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

// Оператор умножения матриц
Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

// Оператор умножения на число
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] * scalar;
    return result;
}

// Транспонирование
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[j][i] = data[i][j];
    return result;
}

// Заполнение матрицы из QTableWidget
void Matrix::fillFromTable(QTableWidget* table) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            QTableWidgetItem* item = table->item(i, j);
            data[i][j] = item ? item->text().toDouble() : 0.0;
        }
}

// Заполнение QTableWidget из матрицы
void Matrix::fillTable(QTableWidget* table) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double value = data[i][j];
            QString text = (value == std::floor(value)) ? QString::number(static_cast<int>(value))
                                                        : QString::number(value, 'g', 3);
            table->setItem(i, j, new QTableWidgetItem(text));
        }
    }
}

// Установка размера таблицы
void Matrix::setSize(QTableWidget* table) {
    table->setRowCount(rows);
    table->setColumnCount(cols);
}

SquareMatrix SquareMatrix::inverse() const {
    int n = rows;
    SquareMatrix result(n);

    // Создаём расширенную матрицу (n x 2n)
    double** augmented = new double*[n];
    for (int i = 0; i < n; ++i) {
        augmented[i] = new double[2 * n]();
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = data[i][j];  // Левая часть
        }
        augmented[i][n + i] = 1.0;  // Правая часть (единичная матрица)
    }

    // Прямой ход метода Гаусса
    for (int i = 0; i < n; ++i) {
        // Поиск ведущего элемента
        if (std::abs(augmented[i][i]) < 1e-9) {
            bool swapped = false;
            for (int k = i + 1; k < n; ++k) {
                if (std::abs(augmented[k][i]) > 1e-9) {
                    std::swap(augmented[i], augmented[k]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                // Матрица вырождена (определитель 0)
                for (int i = 0; i < n; ++i) delete[] augmented[i];
                delete[] augmented;
                throw std::runtime_error("Обратная матрица не существует");
            }
        }

        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= pivot;
        }

        // Обнуление элементов вне главной диагонали
        for (int k = 0; k < n; ++k) {
            if (k == i) continue;
            double factor = augmented[k][i];
            for (int j = 0; j < 2 * n; ++j) {
                augmented[k][j] -= factor * augmented[i][j];
            }
        }
    }

    // Записываем обратную матрицу
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result(i, j) = augmented[i][j + n];

    // Освобождаем память
    for (int i = 0; i < n; ++i) delete[] augmented[i];
    delete[] augmented;

    return result;
}
