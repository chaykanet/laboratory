/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBoxDy;
    QLineEdit *editDy;
    QLineEdit *editDz;
    QDoubleSpinBox *doubleSpinBoxDz;
    QLineEdit *lineMove;
    QDoubleSpinBox *doubleSpinBoxDx;
    QLineEdit *editDx;
    QPushButton *move;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_8;
    QPushButton *scale;
    QDoubleSpinBox *doubleSpinBoxKz;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBoxKx;
    QDoubleSpinBox *doubleSpinBoxKy;
    QLineEdit *lineEdit_7;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_3;
    QDoubleSpinBox *doubleSpinBoxAz;
    QDoubleSpinBox *doubleSpinBoxAx;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_11;
    QDoubleSpinBox *doubleSpinBoxAy;
    QPushButton *rotate;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(603, 538);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 601, 351));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(horizontalLayoutWidget);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout->addWidget(graphicsView);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 350, 201, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBoxDy = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxDy->setObjectName("doubleSpinBoxDy");

        gridLayout->addWidget(doubleSpinBoxDy, 2, 1, 1, 1);

        editDy = new QLineEdit(gridLayoutWidget);
        editDy->setObjectName("editDy");

        gridLayout->addWidget(editDy, 1, 1, 1, 1);

        editDz = new QLineEdit(gridLayoutWidget);
        editDz->setObjectName("editDz");

        gridLayout->addWidget(editDz, 1, 2, 1, 1);

        doubleSpinBoxDz = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxDz->setObjectName("doubleSpinBoxDz");

        gridLayout->addWidget(doubleSpinBoxDz, 2, 2, 1, 1);

        lineMove = new QLineEdit(gridLayoutWidget);
        lineMove->setObjectName("lineMove");

        gridLayout->addWidget(lineMove, 0, 0, 1, 3);

        doubleSpinBoxDx = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxDx->setObjectName("doubleSpinBoxDx");

        gridLayout->addWidget(doubleSpinBoxDx, 2, 0, 1, 1);

        editDx = new QLineEdit(gridLayoutWidget);
        editDx->setObjectName("editDx");

        gridLayout->addWidget(editDx, 1, 0, 1, 1);

        move = new QPushButton(gridLayoutWidget);
        move->setObjectName("move");

        gridLayout->addWidget(move, 3, 0, 1, 3);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(200, 350, 211, 141));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_8 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_8->setObjectName("lineEdit_8");

        gridLayout_2->addWidget(lineEdit_8, 1, 1, 1, 1);

        scale = new QPushButton(gridLayoutWidget_2);
        scale->setObjectName("scale");

        gridLayout_2->addWidget(scale, 3, 0, 1, 3);

        doubleSpinBoxKz = new QDoubleSpinBox(gridLayoutWidget_2);
        doubleSpinBoxKz->setObjectName("doubleSpinBoxKz");

        gridLayout_2->addWidget(doubleSpinBoxKz, 2, 2, 1, 1);

        lineEdit_9 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_9->setObjectName("lineEdit_9");

        gridLayout_2->addWidget(lineEdit_9, 1, 2, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout_2->addWidget(lineEdit_2, 0, 0, 1, 3);

        doubleSpinBoxKx = new QDoubleSpinBox(gridLayoutWidget_2);
        doubleSpinBoxKx->setObjectName("doubleSpinBoxKx");

        gridLayout_2->addWidget(doubleSpinBoxKx, 2, 0, 1, 1);

        doubleSpinBoxKy = new QDoubleSpinBox(gridLayoutWidget_2);
        doubleSpinBoxKy->setObjectName("doubleSpinBoxKy");

        gridLayout_2->addWidget(doubleSpinBoxKy, 2, 1, 1, 1);

        lineEdit_7 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_7->setObjectName("lineEdit_7");

        gridLayout_2->addWidget(lineEdit_7, 1, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(410, 350, 191, 141));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_10 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_10->setObjectName("lineEdit_10");

        gridLayout_3->addWidget(lineEdit_10, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout_3->addWidget(lineEdit_3, 0, 0, 1, 3);

        doubleSpinBoxAz = new QDoubleSpinBox(gridLayoutWidget_3);
        doubleSpinBoxAz->setObjectName("doubleSpinBoxAz");

        gridLayout_3->addWidget(doubleSpinBoxAz, 2, 2, 1, 1);

        doubleSpinBoxAx = new QDoubleSpinBox(gridLayoutWidget_3);
        doubleSpinBoxAx->setObjectName("doubleSpinBoxAx");

        gridLayout_3->addWidget(doubleSpinBoxAx, 2, 0, 1, 1);

        lineEdit_12 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_12->setObjectName("lineEdit_12");

        gridLayout_3->addWidget(lineEdit_12, 1, 2, 1, 1);

        lineEdit_11 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_11->setObjectName("lineEdit_11");

        gridLayout_3->addWidget(lineEdit_11, 1, 1, 1, 1);

        doubleSpinBoxAy = new QDoubleSpinBox(gridLayoutWidget_3);
        doubleSpinBoxAy->setObjectName("doubleSpinBoxAy");

        gridLayout_3->addWidget(doubleSpinBoxAy, 2, 1, 1, 1);

        rotate = new QPushButton(gridLayoutWidget_3);
        rotate->setObjectName("rotate");

        gridLayout_3->addWidget(rotate, 3, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 603, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(action_3);
        menu->addAction(action_2);
        menu->addAction(action_4);
        menu->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        editDy->setText(QCoreApplication::translate("MainWindow", "dy", nullptr));
        editDz->setText(QCoreApplication::translate("MainWindow", "dz", nullptr));
        lineMove->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        editDx->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        move->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "angle x", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "angle z", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "angle y", nullptr));
        rotate->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
