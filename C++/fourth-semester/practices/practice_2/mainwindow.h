#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_matrix1RC_textEdited(const QString &arg1);

    void on_matrix1CC_textEdited(const QString &arg1);

    void on_matrix2CC_textEdited(const QString &arg1);

    void on_matrix2RC_textEdited(const QString &arg1);

    void on_func1_clicked();

    void on_func2_clicked();

    void on_func3_1_clicked();

    void on_func4_clicked();

    void on_func5_clicked();

    void on_func6_clicked();

    void on_func6_2_clicked();

    void on_matrix1_cellDoubleClicked(int row, int column);

    void on_matrix2_cellDoubleClicked(int row, int column);

    void on_matrix3_cellDoubleClicked(int row, int column);

    void showValue(QTableWidget* table, int row, int column);

    void on_testAccess_clicked();

    void on_testNegativeSize_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
