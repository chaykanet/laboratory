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
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_10;
    QDoubleSpinBox *doubleSpinBoxCY;
    QPushButton *rotateButton;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBoxCX;
    QDoubleSpinBox *doubleSpinBoxAX;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *doubleSpinBoxKX;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QPushButton *scaleButton;
    QDoubleSpinBox *doubleSpinBoxKY;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *doubleSpinBoxDX;
    QDoubleSpinBox *doubleSpinBoxDY;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *moveButton;
    QLineEdit *lineEdit_4;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(657, 632);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 651, 401));
        graphicsView->setSceneRect(QRectF(0, 0, 1000, 800));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 400, 651, 161));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        lineEdit_10 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_10->setObjectName("lineEdit_10");

        gridLayout_2->addWidget(lineEdit_10, 1, 0, 1, 1);

        doubleSpinBoxCY = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBoxCY->setObjectName("doubleSpinBoxCY");

        gridLayout_2->addWidget(doubleSpinBoxCY, 2, 1, 1, 1);

        rotateButton = new QPushButton(horizontalLayoutWidget);
        rotateButton->setObjectName("rotateButton");

        gridLayout_2->addWidget(rotateButton, 3, 0, 1, 4);

        lineEdit_3 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout_2->addWidget(lineEdit_3, 1, 1, 1, 1);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout_2->addWidget(lineEdit_2, 1, 2, 1, 2);

        doubleSpinBoxCX = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBoxCX->setObjectName("doubleSpinBoxCX");

        gridLayout_2->addWidget(doubleSpinBoxCX, 2, 0, 1, 1);

        doubleSpinBoxAX = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBoxAX->setObjectName("doubleSpinBoxAX");

        gridLayout_2->addWidget(doubleSpinBoxAX, 2, 2, 1, 2);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 4);


        horizontalLayout->addLayout(gridLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        doubleSpinBoxKX = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBoxKX->setObjectName("doubleSpinBoxKX");

        gridLayout_4->addWidget(doubleSpinBoxKX, 2, 1, 1, 1);

        lineEdit_7 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_7->setObjectName("lineEdit_7");

        gridLayout_4->addWidget(lineEdit_7, 0, 1, 1, 2);

        lineEdit_8 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_8->setObjectName("lineEdit_8");

        gridLayout_4->addWidget(lineEdit_8, 1, 1, 1, 1);

        lineEdit_9 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_9->setObjectName("lineEdit_9");

        gridLayout_4->addWidget(lineEdit_9, 1, 2, 1, 1);

        scaleButton = new QPushButton(horizontalLayoutWidget);
        scaleButton->setObjectName("scaleButton");

        gridLayout_4->addWidget(scaleButton, 3, 1, 1, 2);

        doubleSpinBoxKY = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBoxKY->setObjectName("doubleSpinBoxKY");

        gridLayout_4->addWidget(doubleSpinBoxKY, 2, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        doubleSpinBoxDX = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBoxDX->setObjectName("doubleSpinBoxDX");

        gridLayout_3->addWidget(doubleSpinBoxDX, 2, 1, 1, 1);

        doubleSpinBoxDY = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBoxDY->setObjectName("doubleSpinBoxDY");

        gridLayout_3->addWidget(doubleSpinBoxDY, 2, 2, 1, 1);

        lineEdit_5 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_5->setObjectName("lineEdit_5");

        gridLayout_3->addWidget(lineEdit_5, 1, 1, 1, 1);

        lineEdit_6 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_6->setObjectName("lineEdit_6");

        gridLayout_3->addWidget(lineEdit_6, 1, 2, 1, 1);

        moveButton = new QPushButton(horizontalLayoutWidget);
        moveButton->setObjectName("moveButton");

        gridLayout_3->addWidget(moveButton, 3, 1, 1, 2);

        lineEdit_4 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        gridLayout_3->addWidget(lineEdit_4, 0, 1, 1, 2);


        horizontalLayout->addLayout(gridLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 657, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263 \320\275\320\260\320\267\320\260\320\264", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotateButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "angle x", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\273\321\213 \320\277\320\276\320\262\320\276\321\200\321\202\320\260  \320\276\321\202\320\275 \321\206\320\265\320\275\321\202\321\200\320\260(\320\263\321\200\320\260\320\264.).", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "kX", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "kY", nullptr));
        scaleButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "dX", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "dY", nullptr));
        moveButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201\321\213 \320\277\320\276 x \320\270 y", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
