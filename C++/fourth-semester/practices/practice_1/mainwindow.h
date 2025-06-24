#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readfile.h"
#include "plot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    ReadFile *ReadF;
    Ui::MainWindow *ui;

    Plot *plot;

public slots:
    void sliderValueChanged(int value);
    void exitProgramm();
    void loadFile();
    void refresh();
    void prevSegment();
    void nextSegment();
    void turnButtons(bool flag);
private slots:
    void on_comboBox_activated(int index);
};

#endif // MAINWINDOW_H
