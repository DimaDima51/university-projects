/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *buttonLoad;
    QPushButton *buttonOK;
    QLabel *labelFileName;
    QProgressBar *progressBar;
    QTextEdit *textEditLog;
    QPushButton *buttonMessage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(534, 286);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        buttonLoad = new QPushButton(centralwidget);
        buttonLoad->setObjectName("buttonLoad");
        buttonLoad->setGeometry(QRect(10, 10, 241, 45));
        QFont font;
        font.setPointSize(16);
        buttonLoad->setFont(font);
        buttonOK = new QPushButton(centralwidget);
        buttonOK->setObjectName("buttonOK");
        buttonOK->setEnabled(false);
        buttonOK->setGeometry(QRect(440, 10, 80, 45));
        buttonOK->setFont(font);
        labelFileName = new QLabel(centralwidget);
        labelFileName->setObjectName("labelFileName");
        labelFileName->setGeometry(QRect(10, 70, 511, 36));
        labelFileName->setFont(font);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(10, 130, 511, 44));
        progressBar->setFont(font);
        progressBar->setValue(0);
        textEditLog = new QTextEdit(centralwidget);
        textEditLog->setObjectName("textEditLog");
        textEditLog->setGeometry(QRect(10, 180, 511, 51));
        textEditLog->setFont(font);
        buttonMessage = new QPushButton(centralwidget);
        buttonMessage->setObjectName("buttonMessage");
        buttonMessage->setGeometry(QRect(360, 10, 71, 51));
        buttonMessage->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 534, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Practice 11", nullptr));
        buttonLoad->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        buttonOK->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        labelFileName->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273!", nullptr));
        buttonMessage->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
