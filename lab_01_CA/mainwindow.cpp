#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidget>
#include <QHeaderView>

extern std::vector<std::vector<double>> table_data;

QTableWidget* createCoefficientsTable(const std::vector<double>& coefficients);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    bool ok;
    int polyDegree;
    std::vector<Point> data = {};

    Interp funcValue = Interp(InterpError_t::ERR_OK, 0);
    double xValue = 0;

    std::vector<double> coeffs = {};
    if (ui->radioButton->isChecked())
    {
        xValue = QInputDialog::getDouble(this, "Ввод значения X", "Введите число x:", 0, -1000, 1000, 3, &ok);
        QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");
        int columns = QInputDialog::getDouble(this, "Чтение файла", "Введите кол-во столбцов в файле:", 0, 0, 4, 3, &ok);
        InterpError_t err = readData(fileName.toStdString(), data, columns);
        polyDegree = QInputDialog::getInt(this, "Ввод значения X", "Введите число n:", 0, -1000, 1000, 2, &ok);

        funcValue = interpolate(data, xValue, polyDegree, 0);
    }
    else if (ui->radioButton_2->isChecked())
    {
        xValue = QInputDialog::getDouble(this, "Ввод значения X", "Введите число x:", 0, -1000, 1000, 3, &ok);
        QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");
        int columns = QInputDialog::getDouble(this, "Чтение файла", "Введите кол-во столбцов в файле:", 0, 0, 4, 3, &ok);
        InterpError_t err = readData(fileName.toStdString(), data, columns);
        polyDegree = QInputDialog::getInt(this, "Ввод значения X", "Введите кол-во узлов:", 0, -1000, 1000, 2, &ok);

        funcValue = interpolate(data, xValue, polyDegree, 1);
    }
    else if (ui->radioButton_3->isChecked())
    {
        data = {
            { -1.000, 0, 0.3333333333333333, -0.0 },
            { -0.411, 0.2, 0.3518648838845883, 0.06787271666583986},
            { 0.117, 0.4, 0.41788549937317176, 0.20936421466455568},
            { 0.532, 0.6, 0.5797101449275363, 0.7262875598537634},
            { 0.800,0.8,1.0615711252653928, 4.782886570574242},
            { 0.909, 1, 5.952380952380952, 767.0354848288521},
        };
        xValue = 0;
        polyDegree = QInputDialog::getInt(this, "Ввод значения X", "Введите кол-во узлов:", 0, -1000, 1000, 2, &ok);

        funcValue = interpolate(data, xValue, polyDegree, 1);
    }
    else if (ui->radioButton_4->isChecked())
    {
        data = {
            { -0.291, 0.137, 0 , 0 },
            { -0.264, 0.626, 0, 0 },
            { -0.222, 0.664, 0, 0 },
            { -0.118, 0.731, 0, 0 },
            { 0.171, 0.843, 0, 0 },
            { 0.348, 0.891, 0, 0 },
            { 0.809, 0.985, 0, 0 }
        };
        xValue = 0;
        polyDegree = QInputDialog::getInt(this, "Ввод значения X", "Введите число n:", 0, -1000, 1000, 2, &ok);

        funcValue = interpolate(data, xValue, polyDegree, 0);
    }

    QTableWidget *table = createCoefficientsTable(coeffs);

    ui->verticalLayout_2->addWidget(table);

    if (data.size() == 1)
        QMessageBox::information(this, "Ошибка", QString("Недостаточно точек"));
    else if (funcValue.error == InterpError_t::ERR_MISS_DERIVATIVE)
        QMessageBox::information(this, "Ошибка", QString("Не достаточно производных"));
    else if (funcValue.error == InterpError_t::ERR_RANGE_POLYNOM)
        QMessageBox::information(this, "Ошибка", QString("Неверная степень полинома"));
    else if (funcValue.error == InterpError_t::ERR_SOURCE)
        QMessageBox::information(this, "Ошибка", QString("Ошибка чтения данных"));
    else
    QMessageBox::information(this, "Ответ", QString("Значение функции f(%1) = %2").arg(xValue).arg(funcValue.value));
}

QTableWidget* createCoefficientsTable(const std::vector<double>& coefficients)
{
    // Создаем таблицу

    // Определяем количество строк и столбцов
    size_t rowCount = table_data.size();
    size_t colCount = rowCount > 0 ? table_data[0].size() : 0;

    // Создаем таблицу
    QTableWidget* table = new QTableWidget(rowCount, colCount);

    // Заполняем таблицу данными
    for (size_t i = 0; i < rowCount; ++i) {
        for (size_t j = 0; j < table_data[i].size(); ++j) {
            // Округляем число до 3 знаков после запятой
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(3) << table_data[i][j];
            QString cellValue = QString::fromStdString(oss.str());

            // Создаем элемент таблицы и добавляем его
            QTableWidgetItem* item = new QTableWidgetItem(cellValue);
            table->setItem(i, j, item);
        }
    }

    // Настройка таблицы
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Автоматическое расширение столбцов
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Автоматическое расширение строк
    table->setEditTriggers(QAbstractItemView::NoEditTriggers); // Запрет редактирования

    return table;
}


void MainWindow::on_clear_clicked()
{
    ui->radioButton->clearFocus();
    ui->radioButton_2->clearFocus();
    ui->verticalLayoutWidget_2->close();
}

void MainWindow::on_radioButton_2_clicked()
{
    return;
}

void MainWindow::on_radioButton_clicked()
{
    return;
}

