#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (auto table : {ui->matrix1, ui->matrix2, ui->matrix3}) {
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Сложение матриц
void MainWindow::on_func1_clicked()
{
    int rows1 = ui->matrix1->rowCount();
    int cols1 = ui->matrix1->columnCount();
    int rows2 = ui->matrix2->rowCount();
    int cols2 = ui->matrix2->columnCount();

    try {
        if (rows1 != rows2 || cols1 != cols2) {
            throw SizeMismatchException(); // #3
        }

        bool isSquare = (rows1 == cols1);

        if (isSquare) {
            SquareMatrix matrix1(rows1);
            SquareMatrix matrix2(rows2);

            matrix1.fillFromTable(ui->matrix1);
            matrix2.fillFromTable(ui->matrix2);

            SquareMatrix matrix3 = matrix1 + matrix2;

            matrix3.setSize(ui->matrix3);
            matrix3.fillTable(ui->matrix3);

        } else {
            Matrix matrix1(rows1, cols1);
            Matrix matrix2(rows2, cols2);

            matrix1.fillFromTable(ui->matrix1);
            matrix2.fillFromTable(ui->matrix2);

            Matrix matrix3 = matrix1 + matrix2;

            matrix3.setSize(ui->matrix3);
            matrix3.fillTable(ui->matrix3);
        }
    } catch (const MatrixException& e) {
        e.showMessage();
    }
}

// Умножение матриц
void MainWindow::on_func2_clicked()
{
    int rows1 = ui->matrix1->rowCount();
    int cols1 = ui->matrix1->columnCount();
    int rows2 = ui->matrix2->rowCount();
    int cols2 = ui->matrix2->columnCount();

    if (cols1 != rows2) {
        QMessageBox::warning(this, "Ошибка", "Число столбцов первой матрицы должно быть равно числу строк второй!");
        return;
    }

    Matrix matrix1(rows1, cols1);
    Matrix matrix2(rows2, cols2);

    matrix1.fillFromTable(ui->matrix1);
    matrix2.fillFromTable(ui->matrix2);

    Matrix matrix3 = matrix1 * matrix2;

    matrix3.setSize(ui->matrix3);
    matrix3.fillTable(ui->matrix3);
}

// Вычитание матриц
void MainWindow::on_func5_clicked()
{
    int rows = ui->matrix1->rowCount();
    int cols = ui->matrix1->columnCount();

    if (rows != ui->matrix2->rowCount() || cols != ui->matrix2->columnCount()) {
        QMessageBox::warning(this, "Ошибка", "Размеры матриц должны совпадать!");
        return;
    }

    Matrix matrix1(rows, cols);
    Matrix matrix2(rows, cols);

    matrix1.fillFromTable(ui->matrix1);
    matrix2.fillFromTable(ui->matrix2);

    Matrix matrix3 = matrix1 - matrix2;

    matrix3.setSize(ui->matrix3);
    matrix3.fillTable(ui->matrix3);
}

// Умножение матрицы на число
void MainWindow::on_func3_1_clicked()
{
    int rows = ui->matrix1->rowCount();
    int cols = ui->matrix1->columnCount();
    double scalar = ui->matrix1MultLine->text().toDouble();

    Matrix matrix(rows, cols);
    matrix.fillFromTable(ui->matrix1);

    Matrix result = matrix * scalar;
    result.setSize(ui->matrix3);
    result.fillTable(ui->matrix3);
}

// Приравнивание матриц
void MainWindow::on_func4_clicked()
{
    int rows = ui->matrix1->rowCount();
    int cols = ui->matrix1->columnCount();

    Matrix matrix1(rows, cols);
    matrix1.fillFromTable(ui->matrix1);

    Matrix matrix2 = matrix1;

    matrix2.setSize(ui->matrix2);
    matrix2.fillTable(ui->matrix2);

    ui->matrix2RC->setText(ui->matrix1RC->text());
    ui->matrix2CC->setText(ui->matrix1CC->text());
}

// Транспонирование матрицы
void MainWindow::on_func6_clicked()
{
    int rows = ui->matrix1->rowCount();
    int cols = ui->matrix1->columnCount();

    Matrix matrix(rows, cols);
    matrix.fillFromTable(ui->matrix1);

    Matrix transposed = matrix.transpose();
    transposed.setSize(ui->matrix3);
    transposed.fillTable(ui->matrix3);
}

// Обратная матрица
void MainWindow::on_func6_2_clicked()
{
    int size = ui->matrix1->rowCount();

    if (size != ui->matrix1->columnCount()) {
        QMessageBox::warning(this, "Ошибка", "Матрица должна быть квадратной!");
        return;
    }

    SquareMatrix matrix(size);
    matrix.fillFromTable(ui->matrix1);

    try {
        SquareMatrix inverseMatrix = matrix.inverse();
        inverseMatrix.setSize(ui->matrix3);
        inverseMatrix.fillTable(ui->matrix3);
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Ошибка", "Обратная матрица не существует!");
    }
}


// Отображение значения в ячейке и строке
void MainWindow::showValue(QTableWidget* table, int row, int column)
{
    int rows = table->rowCount();
    int cols = table->columnCount();

    Matrix matrix(rows, cols);
    matrix.fillFromTable(table);

    double value = matrix(row, column);

    QString rowValues;
    for (int col = 0; col < cols; ++col) {
        rowValues += QString::number(matrix(row, col)) + " ";
    }

    QMessageBox::information(this, "Значение ячейки", QString("Значение в ячейке [%1, %2]: %3\nПолная строка: %4").arg(row).arg(column).arg(value).arg(rowValues));
}

// Обработчики изменения размера матриц
void MainWindow::on_matrix1RC_textEdited(const QString &arg1)
{
    ui->matrix1->setRowCount(arg1.toInt());
}

void MainWindow::on_matrix1CC_textEdited(const QString &arg1)
{
    ui->matrix1->setColumnCount(arg1.toInt());
}

void MainWindow::on_matrix2RC_textEdited(const QString &arg1)
{
    ui->matrix2->setRowCount(arg1.toInt());
}

void MainWindow::on_matrix2CC_textEdited(const QString &arg1)
{
    ui->matrix2->setColumnCount(arg1.toInt());
}

// Обработчики двойных кликов на ячейках
void MainWindow::on_matrix1_cellDoubleClicked(int row, int column)
{
    showValue(ui->matrix1, row, column);
}

void MainWindow::on_matrix2_cellDoubleClicked(int row, int column)
{
    showValue(ui->matrix2, row, column);
}

void MainWindow::on_matrix3_cellDoubleClicked(int row, int column)
{
    showValue(ui->matrix3, row, column);
}

void MainWindow::on_testAccess_clicked()
{
    try {
        Matrix m(3, 5);
        double value = m(1000, 1000);
        qDebug() << value << '\n';
    } catch (const MatrixException& e) { // #2
        e.showMessage();
    }
}

void MainWindow::on_testNegativeSize_clicked()
{
    try {
        Matrix m(-5, 3);
    } catch (const MatrixException& e) { // #1
        e.showMessage();
    }
}

