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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QPushButton *pushButtonFigure;
    QPushButton *pushButtonPoint;
    QRadioButton *radioButtonNoDelay;
    QLineEdit *lineEdit_4;
    QRadioButton *radioButtonDelay;
    QLineEdit *lineEdit_2;
    QSpinBox *spinBoxY;
    QSpinBox *spinBoxX;
    QLineEdit *lineEdit;
    QComboBox *comboBoxFon;
    QComboBox *comboBoxFill;
    QTableWidget *tableWidgetPoints;
    QPushButton *pushButtonClear;
    QLineEdit *lineEditTime;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1005, 628);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(5, 1, 631, 521));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(650, 10, 261, 219));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_5 = new QLineEdit(gridLayoutWidget);
        lineEdit_5->setObjectName("lineEdit_5");

        gridLayout->addWidget(lineEdit_5, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout->addWidget(lineEdit_3, 4, 0, 1, 1);

        pushButtonFigure = new QPushButton(gridLayoutWidget);
        pushButtonFigure->setObjectName("pushButtonFigure");

        gridLayout->addWidget(pushButtonFigure, 6, 1, 1, 1);

        pushButtonPoint = new QPushButton(gridLayoutWidget);
        pushButtonPoint->setObjectName("pushButtonPoint");

        gridLayout->addWidget(pushButtonPoint, 6, 0, 1, 1);

        radioButtonNoDelay = new QRadioButton(gridLayoutWidget);
        radioButtonNoDelay->setObjectName("radioButtonNoDelay");

        gridLayout->addWidget(radioButtonNoDelay, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        radioButtonDelay = new QRadioButton(gridLayoutWidget);
        radioButtonDelay->setObjectName("radioButtonDelay");

        gridLayout->addWidget(radioButtonDelay, 3, 1, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 2, 0, 1, 2);

        spinBoxY = new QSpinBox(gridLayoutWidget);
        spinBoxY->setObjectName("spinBoxY");

        gridLayout->addWidget(spinBoxY, 5, 1, 1, 1);

        spinBoxX = new QSpinBox(gridLayoutWidget);
        spinBoxX->setObjectName("spinBoxX");

        gridLayout->addWidget(spinBoxX, 5, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        comboBoxFon = new QComboBox(gridLayoutWidget);
        comboBoxFon->addItem(QString());
        comboBoxFon->addItem(QString());
        comboBoxFon->addItem(QString());
        comboBoxFon->addItem(QString());
        comboBoxFon->addItem(QString());
        comboBoxFon->setObjectName("comboBoxFon");

        gridLayout->addWidget(comboBoxFon, 1, 1, 1, 1);

        comboBoxFill = new QComboBox(gridLayoutWidget);
        comboBoxFill->addItem(QString());
        comboBoxFill->addItem(QString());
        comboBoxFill->addItem(QString());
        comboBoxFill->addItem(QString());
        comboBoxFill->addItem(QString());
        comboBoxFill->setObjectName("comboBoxFill");

        gridLayout->addWidget(comboBoxFill, 0, 1, 1, 1);

        tableWidgetPoints = new QTableWidget(centralwidget);
        tableWidgetPoints->setObjectName("tableWidgetPoints");
        tableWidgetPoints->setGeometry(QRect(650, 240, 256, 192));
        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName("pushButtonClear");
        pushButtonClear->setGeometry(QRect(650, 450, 241, 26));
        lineEditTime = new QLineEdit(centralwidget);
        lineEditTime->setObjectName("lineEditTime");
        lineEditTime->setGeometry(QRect(10, 530, 151, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1005, 23));
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
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButtonFigure->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\274\320\274\320\272\320\275\321\203\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
        pushButtonPoint->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        radioButtonNoDelay->setText(QCoreApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        radioButtonDelay->setText(QCoreApplication::translate("MainWindow", "\320\241 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\276\320\271", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\200\320\265\320\266\320\270\320\274\320\260 \320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\270", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202\320\260 \320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\270", nullptr));
        comboBoxFon->setItemText(0, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));
        comboBoxFon->setItemText(1, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxFon->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxFon->setItemText(3, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBoxFon->setItemText(4, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));

        comboBoxFill->setItemText(0, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxFill->setItemText(1, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));
        comboBoxFill->setItemText(2, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxFill->setItemText(3, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBoxFill->setItemText(4, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));

        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
