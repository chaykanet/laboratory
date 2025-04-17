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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *chartLayout;
    QGraphicsView *graphicsView_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBoxYStart;
    QDoubleSpinBox *doubleSpinBoxXStart;
    QDoubleSpinBox *doubleSpinBoxXEnd;
    QDoubleSpinBox *doubleSpinBoxYEnd;
    QLineEdit *lineEditYEnd;
    QLineEdit *lineEditXEnd;
    QLineEdit *lineEditYStart;
    QLineEdit *lineEditXStart;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_7;
    QComboBox *comboBoxClr;
    QLineEdit *lineEdit_6;
    QComboBox *comboBoxFon;
    QLineEdit *lineEditAlg_2;
    QComboBox *comboBoxAlgos;
    QLineEdit *lineEdit_8;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEditAlg;
    QLineEdit *lineEditLen;
    QLineEdit *lineEditGrad;
    QComboBox *comboBoxAlgos_2;
    QDoubleSpinBox *doubleSpinBoxGrad;
    QDoubleSpinBox *doubleSpinBoxLen;
    QGridLayout *gridLayout_5;
    QComboBox *comboBoxFon_2;
    QComboBox *comboBoxClr_2;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QGraphicsView *graphicsView;
    QPushButton *pushButtonBunch;
    QPushButton *pushButtonClr;
    QPushButton *pushButtonClr_2;
    QPushButton *drawHistogram;
    QPushButton *pushButtonLine;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(923, 659);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 531, 271));
        chartLayout = new QHBoxLayout(horizontalLayoutWidget);
        chartLayout->setSpacing(6);
        chartLayout->setContentsMargins(11, 11, 11, 11);
        chartLayout->setObjectName("chartLayout");
        chartLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView_2 = new QGraphicsView(horizontalLayoutWidget);
        graphicsView_2->setObjectName("graphicsView_2");

        chartLayout->addWidget(graphicsView_2);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(540, 30, 341, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBoxYStart = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxYStart->setObjectName("doubleSpinBoxYStart");

        gridLayout->addWidget(doubleSpinBoxYStart, 1, 1, 1, 1);

        doubleSpinBoxXStart = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxXStart->setObjectName("doubleSpinBoxXStart");

        gridLayout->addWidget(doubleSpinBoxXStart, 0, 1, 1, 1);

        doubleSpinBoxXEnd = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxXEnd->setObjectName("doubleSpinBoxXEnd");

        gridLayout->addWidget(doubleSpinBoxXEnd, 2, 1, 1, 1);

        doubleSpinBoxYEnd = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxYEnd->setObjectName("doubleSpinBoxYEnd");

        gridLayout->addWidget(doubleSpinBoxYEnd, 3, 1, 1, 1);

        lineEditYEnd = new QLineEdit(gridLayoutWidget);
        lineEditYEnd->setObjectName("lineEditYEnd");

        gridLayout->addWidget(lineEditYEnd, 3, 0, 1, 1);

        lineEditXEnd = new QLineEdit(gridLayoutWidget);
        lineEditXEnd->setObjectName("lineEditXEnd");

        gridLayout->addWidget(lineEditXEnd, 2, 0, 1, 1);

        lineEditYStart = new QLineEdit(gridLayoutWidget);
        lineEditYStart->setObjectName("lineEditYStart");

        gridLayout->addWidget(lineEditYStart, 1, 0, 1, 1);

        lineEditXStart = new QLineEdit(gridLayoutWidget);
        lineEditXStart->setObjectName("lineEditXStart");

        gridLayout->addWidget(lineEditXStart, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(540, 141, 341, 81));
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
        comboBoxAlgos->addItem(QString());
        comboBoxAlgos->setObjectName("comboBoxAlgos");

        gridLayout_2->addWidget(comboBoxAlgos, 2, 1, 1, 1);

        lineEdit_8 = new QLineEdit(centralwidget);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(540, 280, 341, 26));
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(540, 310, 341, 192));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEditAlg = new QLineEdit(gridLayoutWidget_3);
        lineEditAlg->setObjectName("lineEditAlg");

        gridLayout_3->addWidget(lineEditAlg, 3, 0, 1, 1);

        lineEditLen = new QLineEdit(gridLayoutWidget_3);
        lineEditLen->setObjectName("lineEditLen");

        gridLayout_3->addWidget(lineEditLen, 1, 0, 1, 1);

        lineEditGrad = new QLineEdit(gridLayoutWidget_3);
        lineEditGrad->setObjectName("lineEditGrad");

        gridLayout_3->addWidget(lineEditGrad, 2, 0, 1, 1);

        comboBoxAlgos_2 = new QComboBox(gridLayoutWidget_3);
        comboBoxAlgos_2->addItem(QString());
        comboBoxAlgos_2->addItem(QString());
        comboBoxAlgos_2->addItem(QString());
        comboBoxAlgos_2->addItem(QString());
        comboBoxAlgos_2->addItem(QString());
        comboBoxAlgos_2->addItem(QString());
        comboBoxAlgos_2->addItem(QString());
        comboBoxAlgos_2->setObjectName("comboBoxAlgos_2");

        gridLayout_3->addWidget(comboBoxAlgos_2, 3, 1, 1, 1);

        doubleSpinBoxGrad = new QDoubleSpinBox(gridLayoutWidget_3);
        doubleSpinBoxGrad->setObjectName("doubleSpinBoxGrad");

        gridLayout_3->addWidget(doubleSpinBoxGrad, 2, 1, 1, 1);

        doubleSpinBoxLen = new QDoubleSpinBox(gridLayoutWidget_3);
        doubleSpinBoxLen->setObjectName("doubleSpinBoxLen");

        gridLayout_3->addWidget(doubleSpinBoxLen, 1, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName("gridLayout_5");
        comboBoxFon_2 = new QComboBox(gridLayoutWidget_3);
        comboBoxFon_2->addItem(QString());
        comboBoxFon_2->addItem(QString());
        comboBoxFon_2->addItem(QString());
        comboBoxFon_2->addItem(QString());
        comboBoxFon_2->addItem(QString());
        comboBoxFon_2->setObjectName("comboBoxFon_2");

        gridLayout_5->addWidget(comboBoxFon_2, 1, 1, 1, 1);

        comboBoxClr_2 = new QComboBox(gridLayoutWidget_3);
        comboBoxClr_2->addItem(QString());
        comboBoxClr_2->addItem(QString());
        comboBoxClr_2->addItem(QString());
        comboBoxClr_2->addItem(QString());
        comboBoxClr_2->addItem(QString());
        comboBoxClr_2->setObjectName("comboBoxClr_2");

        gridLayout_5->addWidget(comboBoxClr_2, 1, 0, 1, 1);

        lineEdit_9 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_9->setObjectName("lineEdit_9");

        gridLayout_5->addWidget(lineEdit_9, 0, 0, 1, 1);

        lineEdit_10 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_10->setObjectName("lineEdit_10");

        gridLayout_5->addWidget(lineEdit_10, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 0, 0, 1, 2);

        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(0, 280, 531, 331));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(gridLayoutWidget_4);
        graphicsView->setObjectName("graphicsView");

        gridLayout_4->addWidget(graphicsView, 1, 0, 1, 1);

        pushButtonBunch = new QPushButton(centralwidget);
        pushButtonBunch->setObjectName("pushButtonBunch");
        pushButtonBunch->setGeometry(QRect(540, 510, 341, 26));
        pushButtonClr = new QPushButton(centralwidget);
        pushButtonClr->setObjectName("pushButtonClr");
        pushButtonClr->setGeometry(QRect(540, 250, 341, 26));
        pushButtonClr_2 = new QPushButton(centralwidget);
        pushButtonClr_2->setObjectName("pushButtonClr_2");
        pushButtonClr_2->setGeometry(QRect(540, 540, 341, 26));
        drawHistogram = new QPushButton(centralwidget);
        drawHistogram->setObjectName("drawHistogram");
        drawHistogram->setGeometry(QRect(540, 0, 341, 26));
        pushButtonLine = new QPushButton(centralwidget);
        pushButtonLine->setObjectName("pushButtonLine");
        pushButtonLine->setGeometry(QRect(540, 220, 341, 26));
        MainWindow->setCentralWidget(centralwidget);
        pushButtonClr_2->raise();
        horizontalLayoutWidget->raise();
        gridLayoutWidget->raise();
        gridLayoutWidget_2->raise();
        lineEdit_8->raise();
        gridLayoutWidget_3->raise();
        gridLayoutWidget_4->raise();
        pushButtonBunch->raise();
        pushButtonClr->raise();
        drawHistogram->raise();
        pushButtonLine->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 923, 23));
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
        lineEditYEnd->setText(QCoreApplication::translate("MainWindow", "Y \320\272\320\276\320\275\321\206\320\260:", nullptr));
        lineEditXEnd->setText(QCoreApplication::translate("MainWindow", "X \320\272\320\276\320\275\321\206\320\260:", nullptr));
        lineEditYStart->setText(QCoreApplication::translate("MainWindow", "Y \320\275\320\260\321\207\320\260\320\273\320\260:", nullptr));
        lineEditXStart->setText(QCoreApplication::translate("MainWindow", "X \320\275\320\260\321\207\320\260\320\273\320\260:", nullptr));
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
        comboBoxAlgos->setItemText(0, QCoreApplication::translate("MainWindow", "\320\221\321\200-\321\205\320\265\320\274.", nullptr));
        comboBoxAlgos->setItemText(1, QCoreApplication::translate("MainWindow", "\320\221\321\200-\321\205\320\265\320\274. \320\264\320\265\320\271\321\201\321\202.", nullptr));
        comboBoxAlgos->setItemText(2, QCoreApplication::translate("MainWindow", "\320\221\321\200-\321\205\320\265\320\274. \320\261\320\265\320\267 \321\201\321\202\321\203\320\277.", nullptr));
        comboBoxAlgos->setItemText(3, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263-\320\274. \320\222\321\203.", nullptr));
        comboBoxAlgos->setItemText(4, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263-\320\274. \320\246\320\224\320\220.", nullptr));
        comboBoxAlgos->setItemText(5, QString());

        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\260 \320\277\321\203\321\207\320\272\320\260", nullptr));
        lineEditAlg->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        lineEditLen->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        lineEditGrad->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263 \320\262 \320\263\321\200\320\260\320\264.", nullptr));
        comboBoxAlgos_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\221\321\200-\321\205\320\265\320\274.", nullptr));
        comboBoxAlgos_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\221\321\200-\321\205\320\265\320\274. \320\264\320\265\320\271\321\201\321\202.", nullptr));
        comboBoxAlgos_2->setItemText(2, QCoreApplication::translate("MainWindow", "\320\221\321\200-\321\205\320\265\320\274. \320\261\320\265\320\267 \321\201\321\202\321\203\320\277.", nullptr));
        comboBoxAlgos_2->setItemText(3, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263-\320\274. \320\222\321\203.", nullptr));
        comboBoxAlgos_2->setItemText(4, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263-\320\274. \320\246\320\224\320\220.", nullptr));
        comboBoxAlgos_2->setItemText(5, QString());
        comboBoxAlgos_2->setItemText(6, QString());

        comboBoxFon_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxFon_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBoxFon_2->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        comboBoxFon_2->setItemText(3, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxFon_2->setItemText(4, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));

        comboBoxClr_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxClr_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBoxClr_2->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        comboBoxClr_2->setItemText(3, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxClr_2->setItemText(4, QCoreApplication::translate("MainWindow", "\320\221\320\265\320\273\321\213\320\271", nullptr));

        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\270", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        pushButtonBunch->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\277\321\203\321\207\320\276\320\272", nullptr));
        pushButtonClr->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButtonClr_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        drawHistogram->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270 \320\267\320\260\320\274\320\265\321\200", nullptr));
        pushButtonLine->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\277\321\200\321\217\320\274\321\203\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
