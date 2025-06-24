#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class ReadFile;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonLoad_clicked();
    void on_buttonOK_clicked();
    void on_buttonMessage_clicked();

private:
    Ui::MainWindow *ui;
    ReadFile *rf;
    QString filePath;
};

#endif // MAINWINDOW_H
