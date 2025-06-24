#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ReadFile.h"
#include <QFileDialog>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    rf(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonLoad_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, "Открытие файла");
    if (filePath.isEmpty()) {
        ui->labelFileName->setText("Выберите файл!");
        ui->buttonOK->setEnabled(false);
    } else {
        ui->labelFileName->setText(filePath);
        ui->buttonOK->setEnabled(1);
    }
}

void MainWindow::on_buttonOK_clicked()
{
    delete rf;
    rf = nullptr;

    ui->buttonOK->setEnabled(false);
    ui->progressBar->setValue(0);

    rf = new ReadFile(filePath, ui->progressBar, ui->buttonOK, ui->textEditLog, this);
    rf->start();
}

void MainWindow::on_buttonMessage_clicked()
{
    QMessageBox::information(this, "test", "Тестовое сообщение");
}

