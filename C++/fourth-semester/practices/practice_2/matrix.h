#ifndef MATRIX_H
#define MATRIX_H

#include <QMessageBox>
#include <QTableWidget>

// Базовый абстрактный класс исключения
class MatrixException {
    public:
        virtual ~MatrixException() {}
        virtual void showMessage() const = 0;
};

// 1) Отрицательный размер
class NegativeSizeException : public MatrixException {
    public:
        void showMessage() const {
            QMessageBox::warning(nullptr, "Ошибка", "Количество строк и столбцов не может быть отрицательным!");
        }
};

// 2) Индекс выходит за границы
class IndexOutOfBoundsException : public MatrixException {
    public:
        void showMessage() const {
            QMessageBox::warning(nullptr, "Ошибка", "Индекс выходит за границы матрицы!");
        }
};

// 3) Несовпадение размеров при сложении/вычитании
class SizeMismatchException : public MatrixException {
    public:
        void showMessage() const {
            QMessageBox::warning(nullptr, "Ошибка", "Размеры матриц должны совпадать!");
        }
};

class Matrix {
    public:
        Matrix(int rows, int cols);
        Matrix(const Matrix& other);
        ~Matrix();

        Matrix& operator=(const Matrix& other);

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(double scalar) const;

        double* operator[](int row);
        const double* operator[](int row) const;

        double& operator()(int row, int col);
        const double& operator()(int row, int col) const;

        Matrix transpose() const;

        void fillFromTable(QTableWidget* table);
        void fillTable(QTableWidget* table) const;
        void setSize(QTableWidget* table);

    protected:
        int rows, cols;
        double** data;
        void allocateMemory();
        void freeMemory();
};

class SquareMatrix : public Matrix {
    public:
        SquareMatrix(int size) : Matrix(size, size) {}
        SquareMatrix(const Matrix& other) : Matrix(other) {}

        SquareMatrix& operator=(const Matrix& other) {
            Matrix::operator=(other);
            return *this;
        }

        SquareMatrix inverse() const;
};

#endif // MATRIX_H
