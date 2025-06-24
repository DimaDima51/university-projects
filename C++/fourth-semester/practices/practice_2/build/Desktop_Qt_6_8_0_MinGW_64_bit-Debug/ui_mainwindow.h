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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *matrix1;
    QLabel *label;
    QLineEdit *matrix1CC;
    QLineEdit *matrix1RC;
    QLabel *label_2;
    QLineEdit *matrix2RC;
    QTableWidget *matrix2;
    QLineEdit *matrix2CC;
    QTableWidget *matrix3;
    QPushButton *func1;
    QPushButton *func2;
    QPushButton *func5;
    QPushButton *func3_1;
    QLineEdit *matrix1MultLine;
    QPushButton *func4;
    QPushButton *func6;
    QPushButton *func6_2;
    QPushButton *testAccess;
    QPushButton *testNegativeSize;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 777);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        matrix1 = new QTableWidget(centralwidget);
        if (matrix1->columnCount() < 3)
            matrix1->setColumnCount(3);
        if (matrix1->rowCount() < 3)
            matrix1->setRowCount(3);
        matrix1->setObjectName("matrix1");
        matrix1->setGeometry(QRect(30, 30, 301, 261));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(matrix1->sizePolicy().hasHeightForWidth());
        matrix1->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(28);
        matrix1->setFont(font);
        matrix1->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        matrix1->setTextElideMode(Qt::TextElideMode::ElideLeft);
        matrix1->setRowCount(3);
        matrix1->setColumnCount(3);
        matrix1->horizontalHeader()->setVisible(false);
        matrix1->horizontalHeader()->setCascadingSectionResizes(true);
        matrix1->horizontalHeader()->setHighlightSections(true);
        matrix1->verticalHeader()->setVisible(false);
        matrix1->verticalHeader()->setCascadingSectionResizes(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 300, 20, 31));
        matrix1CC = new QLineEdit(centralwidget);
        matrix1CC->setObjectName("matrix1CC");
        matrix1CC->setGeometry(QRect(110, 300, 51, 31));
        QFont font1;
        font1.setPointSize(14);
        matrix1CC->setFont(font1);
        matrix1RC = new QLineEdit(centralwidget);
        matrix1RC->setObjectName("matrix1RC");
        matrix1RC->setGeometry(QRect(30, 300, 51, 31));
        matrix1RC->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 690, 20, 31));
        matrix2RC = new QLineEdit(centralwidget);
        matrix2RC->setObjectName("matrix2RC");
        matrix2RC->setGeometry(QRect(30, 690, 51, 31));
        matrix2RC->setFont(font1);
        matrix2 = new QTableWidget(centralwidget);
        if (matrix2->columnCount() < 3)
            matrix2->setColumnCount(3);
        if (matrix2->rowCount() < 3)
            matrix2->setRowCount(3);
        matrix2->setObjectName("matrix2");
        matrix2->setGeometry(QRect(30, 420, 301, 261));
        sizePolicy.setHeightForWidth(matrix2->sizePolicy().hasHeightForWidth());
        matrix2->setSizePolicy(sizePolicy);
        matrix2->setFont(font);
        matrix2->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        matrix2->setTextElideMode(Qt::TextElideMode::ElideLeft);
        matrix2->setRowCount(3);
        matrix2->setColumnCount(3);
        matrix2->horizontalHeader()->setVisible(false);
        matrix2->horizontalHeader()->setCascadingSectionResizes(true);
        matrix2->horizontalHeader()->setHighlightSections(true);
        matrix2->verticalHeader()->setVisible(false);
        matrix2->verticalHeader()->setCascadingSectionResizes(true);
        matrix2CC = new QLineEdit(centralwidget);
        matrix2CC->setObjectName("matrix2CC");
        matrix2CC->setGeometry(QRect(110, 690, 51, 31));
        matrix2CC->setFont(font1);
        matrix3 = new QTableWidget(centralwidget);
        if (matrix3->columnCount() < 3)
            matrix3->setColumnCount(3);
        if (matrix3->rowCount() < 3)
            matrix3->setRowCount(3);
        matrix3->setObjectName("matrix3");
        matrix3->setEnabled(true);
        matrix3->setGeometry(QRect(460, 200, 321, 321));
        sizePolicy.setHeightForWidth(matrix3->sizePolicy().hasHeightForWidth());
        matrix3->setSizePolicy(sizePolicy);
        matrix3->setFont(font);
        matrix3->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        matrix3->setTextElideMode(Qt::TextElideMode::ElideLeft);
        matrix3->setRowCount(3);
        matrix3->setColumnCount(3);
        matrix3->horizontalHeader()->setVisible(false);
        matrix3->horizontalHeader()->setCascadingSectionResizes(true);
        matrix3->horizontalHeader()->setHighlightSections(true);
        matrix3->verticalHeader()->setVisible(false);
        matrix3->verticalHeader()->setCascadingSectionResizes(true);
        func1 = new QPushButton(centralwidget);
        func1->setObjectName("func1");
        func1->setGeometry(QRect(20, 350, 41, 51));
        QFont font2;
        font2.setPointSize(20);
        func1->setFont(font2);
        func2 = new QPushButton(centralwidget);
        func2->setObjectName("func2");
        func2->setGeometry(QRect(120, 350, 41, 51));
        func2->setFont(font2);
        func5 = new QPushButton(centralwidget);
        func5->setObjectName("func5");
        func5->setGeometry(QRect(70, 350, 41, 51));
        func5->setFont(font2);
        func3_1 = new QPushButton(centralwidget);
        func3_1->setObjectName("func3_1");
        func3_1->setGeometry(QRect(350, 130, 41, 51));
        func3_1->setFont(font2);
        matrix1MultLine = new QLineEdit(centralwidget);
        matrix1MultLine->setObjectName("matrix1MultLine");
        matrix1MultLine->setGeometry(QRect(410, 140, 51, 31));
        matrix1MultLine->setFont(font1);
        func4 = new QPushButton(centralwidget);
        func4->setObjectName("func4");
        func4->setGeometry(QRect(170, 350, 41, 51));
        func4->setFont(font2);
        func6 = new QPushButton(centralwidget);
        func6->setObjectName("func6");
        func6->setGeometry(QRect(220, 350, 41, 51));
        func6->setFont(font2);
        func6_2 = new QPushButton(centralwidget);
        func6_2->setObjectName("func6_2");
        func6_2->setGeometry(QRect(280, 350, 61, 51));
        func6_2->setFont(font2);
        testAccess = new QPushButton(centralwidget);
        testAccess->setObjectName("testAccess");
        testAccess->setGeometry(QRect(710, 660, 51, 51));
        testNegativeSize = new QPushButton(centralwidget);
        testNegativeSize->setObjectName("testNegativeSize");
        testNegativeSize->setGeometry(QRect(650, 660, 51, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        matrix1CC->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        matrix1RC->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        matrix2RC->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        matrix2CC->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        func1->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        func2->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        func5->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        func3_1->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        matrix1MultLine->setText(QString());
        func4->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        func6->setText(QCoreApplication::translate("MainWindow", "^T", nullptr));
        func6_2->setText(QCoreApplication::translate("MainWindow", "^-1", nullptr));
        testAccess->setText(QCoreApplication::translate("MainWindow", "#2", nullptr));
        testNegativeSize->setText(QCoreApplication::translate("MainWindow", "#1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
