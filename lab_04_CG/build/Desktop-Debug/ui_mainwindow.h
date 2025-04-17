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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *chartLayout;
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_7;
    QComboBox *comboBoxClr;
    QLineEdit *lineEdit_6;
    QComboBox *comboBoxFon;
    QLineEdit *lineEditAlg_2;
    QComboBox *comboBoxAlgos;
    QPushButton *pushButtonClrear;
    QPushButton *pushButtonGraphs;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QDoubleSpinBox *doubleSpinBoxR;
    QDoubleSpinBox *doubleSpinBoxB;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBoxA;
    QPushButton *pushButtonCircle;
    QPushButton *pushButtonEllipse;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QDoubleSpinBox *doubleSpinBoxXc;
    QDoubleSpinBox *doubleSpinBoxYc;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_8;
    QDoubleSpinBox *doubleSpinBoxAStart;
    QDoubleSpinBox *doubleSpinBoxRStart;
    QLineEdit *lineEdit_10;
    QSpinBox *spinBoxStepSpec;
    QPushButton *pushButtonCircleSpec;
    QLineEdit *lineEdit_9;
    QDoubleSpinBox *doubleSpinBoxBStart;
    QPushButton *pushButtonEllipseSpec;
    QLineEdit *lineEdit_11;
    QSpinBox *spinBoxNumsSpec;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(984, 659);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 631, 601));
        chartLayout = new QHBoxLayout(horizontalLayoutWidget);
        chartLayout->setSpacing(6);
        chartLayout->setContentsMargins(11, 11, 11, 11);
        chartLayout->setObjectName("chartLayout");
        chartLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(horizontalLayoutWidget);
        graphicsView->setObjectName("graphicsView");

        chartLayout->addWidget(graphicsView);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(640, 10, 341, 92));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_7 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_7->setObjectName("lineEdit_7");

        gridLayout_2->addWidget(lineEdit_7, 0, 1, 1, 1);

        comboBoxClr = new QComboBox(gridLayoutWidget_2);
        comboBoxClr->addItem(QString());
        comboBoxClr->addItem(QString());
        comboBoxClr->addItem(QString());
        comboBoxClr->addItem(QString());
        comboBoxClr->addItem(QString());
        comboBoxClr->setObjectName("comboBoxClr");

        gridLayout_2->addWidget(comboBoxClr, 1, 0, 1, 1);

        lineEdit_6 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_6->setObjectName("lineEdit_6");

        gridLayout_2->addWidget(lineEdit_6, 0, 0, 1, 1);

        comboBoxFon = new QComboBox(gridLayoutWidget_2);
        comboBoxFon->addItem(QString());
        comboBoxFon->addItem(QString());
        comboBoxFon->addItem(QString());
        comboBoxFon->addItem(QString());
        comboBoxFon->addItem(QString());
        comboBoxFon->setObjectName("comboBoxFon");

        gridLayout_2->addWidget(comboBoxFon, 1, 1, 1, 1);

        lineEditAlg_2 = new QLineEdit(gridLayoutWidget_2);
        lineEditAlg_2->setObjectName("lineEditAlg_2");

        gridLayout_2->addWidget(lineEditAlg_2, 2, 0, 1, 1);

        comboBoxAlgos = new QComboBox(gridLayoutWidget_2);
        comboBoxAlgos->addItem(QString());
        comboBoxAlgos->addItem(QString());
        comboBoxAlgos->addItem(QString());
        comboBoxAlgos->addItem(QString());
        comboBoxAlgos->addItem(QString());
        comboBoxAlgos->setObjectName("comboBoxAlgos");

        gridLayout_2->addWidget(comboBoxAlgos, 2, 1, 1, 1);

        pushButtonClrear = new QPushButton(centralwidget);
        pushButtonClrear->setObjectName("pushButtonClrear");
        pushButtonClrear->setGeometry(QRect(640, 480, 341, 26));
        pushButtonGraphs = new QPushButton(centralwidget);
        pushButtonGraphs->setObjectName("pushButtonGraphs");
        pushButtonGraphs->setGeometry(QRect(640, 510, 341, 26));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(640, 210, 341, 93));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        doubleSpinBoxR = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxR->setObjectName("doubleSpinBoxR");

        gridLayout->addWidget(doubleSpinBoxR, 1, 0, 1, 1);

        doubleSpinBoxB = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxB->setObjectName("doubleSpinBoxB");

        gridLayout->addWidget(doubleSpinBoxB, 1, 2, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 2);

        doubleSpinBoxA = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxA->setObjectName("doubleSpinBoxA");

        gridLayout->addWidget(doubleSpinBoxA, 1, 1, 1, 1);

        pushButtonCircle = new QPushButton(gridLayoutWidget);
        pushButtonCircle->setObjectName("pushButtonCircle");

        gridLayout->addWidget(pushButtonCircle, 2, 0, 1, 1);

        pushButtonEllipse = new QPushButton(gridLayoutWidget);
        pushButtonEllipse->setObjectName("pushButtonEllipse");

        gridLayout->addWidget(pushButtonEllipse, 2, 1, 1, 2);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(640, 110, 341, 93));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout_3->addWidget(lineEdit_3, 0, 0, 1, 2);

        lineEdit_5 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_5->setObjectName("lineEdit_5");

        gridLayout_3->addWidget(lineEdit_5, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_4->setObjectName("lineEdit_4");

        gridLayout_3->addWidget(lineEdit_4, 1, 0, 1, 1);

        doubleSpinBoxXc = new QDoubleSpinBox(gridLayoutWidget_3);
        doubleSpinBoxXc->setObjectName("doubleSpinBoxXc");

        gridLayout_3->addWidget(doubleSpinBoxXc, 2, 0, 1, 1);

        doubleSpinBoxYc = new QDoubleSpinBox(gridLayoutWidget_3);
        doubleSpinBoxYc->setObjectName("doubleSpinBoxYc");

        gridLayout_3->addWidget(doubleSpinBoxYc, 2, 1, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(640, 310, 344, 159));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_8 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_8->setObjectName("lineEdit_8");

        gridLayout_4->addWidget(lineEdit_8, 0, 0, 1, 1);

        doubleSpinBoxAStart = new QDoubleSpinBox(gridLayoutWidget_4);
        doubleSpinBoxAStart->setObjectName("doubleSpinBoxAStart");

        gridLayout_4->addWidget(doubleSpinBoxAStart, 1, 1, 1, 1);

        doubleSpinBoxRStart = new QDoubleSpinBox(gridLayoutWidget_4);
        doubleSpinBoxRStart->setObjectName("doubleSpinBoxRStart");

        gridLayout_4->addWidget(doubleSpinBoxRStart, 1, 0, 1, 1);

        lineEdit_10 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_10->setObjectName("lineEdit_10");

        gridLayout_4->addWidget(lineEdit_10, 4, 0, 1, 1);

        spinBoxStepSpec = new QSpinBox(gridLayoutWidget_4);
        spinBoxStepSpec->setObjectName("spinBoxStepSpec");

        gridLayout_4->addWidget(spinBoxStepSpec, 4, 1, 1, 2);

        pushButtonCircleSpec = new QPushButton(gridLayoutWidget_4);
        pushButtonCircleSpec->setObjectName("pushButtonCircleSpec");

        gridLayout_4->addWidget(pushButtonCircleSpec, 2, 0, 1, 1);

        lineEdit_9 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_9->setObjectName("lineEdit_9");

        gridLayout_4->addWidget(lineEdit_9, 0, 1, 1, 2);

        doubleSpinBoxBStart = new QDoubleSpinBox(gridLayoutWidget_4);
        doubleSpinBoxBStart->setObjectName("doubleSpinBoxBStart");

        gridLayout_4->addWidget(doubleSpinBoxBStart, 1, 2, 1, 1);

        pushButtonEllipseSpec = new QPushButton(gridLayoutWidget_4);
        pushButtonEllipseSpec->setObjectName("pushButtonEllipseSpec");

        gridLayout_4->addWidget(pushButtonEllipseSpec, 2, 1, 1, 2);

        lineEdit_11 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_11->setObjectName("lineEdit_11");

        gridLayout_4->addWidget(lineEdit_11, 3, 0, 1, 1);

        spinBoxNumsSpec = new QSpinBox(gridLayoutWidget_4);
        spinBoxNumsSpec->setObjectName("spinBoxNumsSpec");

        gridLayout_4->addWidget(spinBoxNumsSpec, 3, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 984, 23));
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
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        comboBoxClr->setItemText(0, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxClr->setItemText(1, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBoxClr->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        comboBoxClr->setItemText(3, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxClr->setItemText(4, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));

        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\270", nullptr));
        comboBoxFon->setItemText(0, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxFon->setItemText(1, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBoxFon->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        comboBoxFon->setItemText(3, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxFon->setItemText(4, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));

        lineEditAlg_2->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        comboBoxAlgos->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274. \320\262\320\270\320\264", nullptr));
        comboBoxAlgos->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\276\320\275. \320\262\320\270\320\264", nullptr));
        comboBoxAlgos->setItemText(2, QCoreApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274", nullptr));
        comboBoxAlgos->setItemText(3, QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        comboBoxAlgos->setItemText(4, QCoreApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273. \321\204\321\203\320\275\320\272\321\206\320\270\321\217", nullptr));

        pushButtonClrear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButtonGraphs->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270 \320\267\320\260\320\274\320\265\321\200\321\213", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\320\276\321\201\320\270 \320\260 \320\270 b", nullptr));
        pushButtonCircle->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        pushButtonEllipse->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\215\320\273\320\273\320\270\320\277\321\201", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "Yc", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "Xc", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207. \320\240\320\260\320\264\320\270\321\203\321\201 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButtonCircleSpec->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202-\320\262\320\260\321\202\321\214 \321\201\320\277\320\265\320\272\321\202\321\200 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207. \320\237\320\276\320\273\321\203\320\276\321\201\320\270 \320\260 \320\270 b", nullptr));
        pushButtonEllipseSpec->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202-\320\262\320\260\321\202\321\214 \321\201\320\277\320\265\320\272\321\202\321\200 \321\215\320\273\320\273\320\270\320\277\321\201\320\260", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\276\321\202\321\200\320\270\321\201\320\276\320\262\320\276\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
