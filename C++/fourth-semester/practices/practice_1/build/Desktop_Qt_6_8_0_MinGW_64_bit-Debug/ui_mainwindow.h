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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionExit;
    QAction *action_2;
    QAction *changeColor;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QSlider *verticalSlider;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QComboBox *comboBox;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(835, 573);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName("actionFile");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        changeColor = new QAction(MainWindow);
        changeColor->setObjectName("changeColor");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 771, 471));
        graphicsView->setDragMode(QGraphicsView::DragMode::NoDrag);
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setEnabled(true);
        verticalSlider->setGeometry(QRect(800, 10, 20, 471));
        verticalSlider->setMinimum(10);
        verticalSlider->setMaximum(500);
        verticalSlider->setSingleStep(10);
        verticalSlider->setPageStep(10);
        verticalSlider->setValue(200);
        verticalSlider->setOrientation(Qt::Orientation::Vertical);
        verticalSlider->setTickPosition(QSlider::TickPosition::TicksBothSides);
        verticalSlider->setTickInterval(10);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(790, 490, 41, 20));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-730, 490, 80, 24));
        leftButton = new QPushButton(centralwidget);
        leftButton->setObjectName("leftButton");
        leftButton->setGeometry(QRect(10, 490, 83, 29));
        rightButton = new QPushButton(centralwidget);
        rightButton->setObjectName("rightButton");
        rightButton->setGeometry(QRect(100, 490, 83, 29));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(590, 490, 191, 28));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 835, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName("menuMenu");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addSeparator();
        menuMenu->addAction(actionFile);
        menuMenu->addAction(actionExit);
        menuMenu->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFile->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        changeColor->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "<==", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "==>", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
