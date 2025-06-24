#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , plot(new Plot())
{
    ui->setupUi(this);
    connect(ui->actionFile, SIGNAL(triggered()), SLOT(loadFile()));
    connect(ui->actionExit, SIGNAL(triggered()), SLOT(exitProgramm()));
    connect(ui->verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(int)));
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(refresh()));

    connect(ui->leftButton, &QPushButton::clicked, this, &MainWindow::prevSegment);
    connect(ui->rightButton, &QPushButton::clicked, this, &MainWindow::nextSegment);

    ui->comboBox->addItem("Красный", QColor(Qt::red));
    ui->comboBox->addItem("Белый", QColor(Qt::white));
    ui->comboBox->addItem("Зеленый", QColor(Qt::green));

    turnButtons(false);
}

MainWindow::~MainWindow() {
    delete ui;
    delete plot;
}

void MainWindow::sliderValueChanged(int value) {
    ui->label->setNum(value);
    refresh();
}

void MainWindow::exitProgramm() {
    QApplication::quit();
}

void MainWindow::loadFile() {
    QString FileName = QFileDialog::getOpenFileName();

    turnButtons(false);

    if (FileName.isEmpty()) {
        return;
    }

    FileName.replace(QString('/'), QString("\\"));
    ReadF = new ReadFile(FileName);

    turnButtons(true);
    refresh();
}

void MainWindow::refresh() {
    if (ReadF) {
        ReadF->ReadF();
        plot->draw(*ui, *ReadF);
    }
}

void MainWindow::prevSegment() {
    if (ReadF) {
        plot->prevSegment(*ui, *ReadF);
    }
}

void MainWindow::nextSegment() {
    if (ReadF) {
        plot->nextSegment(*ui, *ReadF);
    }
}

void MainWindow::on_comboBox_activated(int index) {
    refresh();
}


void MainWindow::turnButtons(bool flag) {
    ui->label->setEnabled(flag);
    ui->verticalSlider->setEnabled(flag);
    ui->leftButton->setEnabled(flag);
    ui->rightButton->setEnabled(flag);
    ui->comboBox->setEnabled(flag);
}



