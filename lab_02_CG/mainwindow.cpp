#include "mainwindow.h"
#include "input.h"
#include "ui_mainwindow.h"

#include "QMessageBox"

#include "error.h"
#include "figure.h"
#include "actions.h"

QList<Fish> history;

QPointF pointCenter;

#define WIDTH 1000
#define HEIGHT 800

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);
    ui->lineEdit_7->setReadOnly(true);
    ui->lineEdit_8->setReadOnly(true);
    ui->lineEdit_9->setReadOnly(true);
    ui->lineEdit_10->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);

    ui->doubleSpinBoxAX->setRange(-360, 360);

    ui->doubleSpinBoxDX->setRange(-1000, 1000);
    ui->doubleSpinBoxDY->setRange(-1000, 1000);

    ui->doubleSpinBoxCX->setRange(-1000, 1000);
    ui->doubleSpinBoxCY->setRange(-1000, 1000);

    ui->doubleSpinBoxKX->setRange(-100, 100);
    ui->doubleSpinBoxKY->setRange(-100, 100);

    connect(ui->action, &QAction::triggered, this,
            &MainWindow::on_actionLoad_clicked);

    connect(ui->action_2, &QAction::triggered, this,
            &MainWindow::exitApp);

    connect(ui->action_3, &QAction::triggered, this,
            &MainWindow::step_back);
}

void MainWindow::exitApp()
{
    QApplication::quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_clicked()
{
    Fish fish;

    myerror_t rc = dowlandFigure(fish.fins, "/home/chayka/lab_02_CG/data/fins.txt");

    if (rc == ERR_OK)
        rc = dowlandFigure(fish.tail, "/home/chayka/lab_02_CG/data/tail.txt");

    if (rc == ERR_OK)
        rc = dowlandFigure(fish.head, "/home/chayka/lab_02_CG/data/head.txt");

    if (rc == ERR_OK)
    {
        Figure arc;

        QList<QPointF> points;
        Edges_t edges;

        makeArc(points, edges);
        arc.setPoints(points);
        arc.setEdges(edges);
        arc.center = fish.body.center;
        fish.arc = arc;
    }

    if (rc == ERR_OK)
        rc = dowlandEllipse(fish.body, "/home/chayka/lab_02_CG/data/body.txt");

    if (rc == ERR_OK)
        rc = dowlandEllipse(fish.eye, "/home/chayka/lab_02_CG/data/eye.txt");

    if (rc == ERR_OK)
    {
        fish.eye.center = QPointF(0, 0);
    }

    if (rc != ERR_OK)
        QMessageBox::critical(this, "Ошибка", QString("Фигура не была загружена."));

    if (rc == ERR_OK)
    {
        history.append(fish);

        draw();
    }
}

void MainWindow::draw()
{
    QGraphicsScene *scene = ui->graphicsView->scene();

    scene->clear();

    QImage image = QImage(WIDTH, HEIGHT, QImage::Format_RGB32);

    image.fill(Qt::white);

    QPainter p(&image);

    drawAxes(p);
    p.setPen(Qt::red);
    p.drawEllipse(pointCenter.x() + WIDTH / 2, pointCenter.y() + HEIGHT / 2, 5, 5);

    p.setPen(Qt::black);

    drawFish(p, history[history.size() - 1]);

    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateButton_clicked()
{
    Rotate rotate = Rotate(ui->doubleSpinBoxAX->value() * M_PI / 180);

    qreal xCenter = ui->doubleSpinBoxCX->value();
    qreal yCenter = -ui->doubleSpinBoxCY->value();

    QPointF center = QPointF(xCenter, yCenter);

    if (history.size())
    {
        Fish new_fish = history[history.size() - 1];

        new_fish.body.center = center;
        new_fish.arc.center = center;
        new_fish.fins.center = center;
        new_fish.tail.center = center;
        new_fish.eye.center = center;
        new_fish.head.center = center;

        myerror_t rc = rotateFish(new_fish, rotate);

        if (rc == ERR_OK)
        {
            history.append(new_fish);

            pointCenter = new_fish.body.center;
            draw();
        }

        if (rc != ERR_OK)
            QMessageBox::critical(this, "Ошибка", QString("Ошибка при повороте."));
    }
    else
        QMessageBox::critical(this, "Ошибка", QString("Фигура не отрисована."));
}

void MainWindow::on_moveButton_clicked()
{
    Vect vect = Vect(ui->doubleSpinBoxDX->value(), -ui->doubleSpinBoxDY->value());

    if (history.size())
    {
        Fish new_fish = history[history.size() - 1];

        myerror_t rc = moveFish(new_fish, vect);

        if (rc == ERR_OK)
        {
            history.append(new_fish);
            pointCenter = new_fish.body.center;
            draw();
        }

        if (rc != ERR_OK)
            QMessageBox::critical(this, "Ошибка", QString("Ошибка переноса фигуры.").arg(rc));
    }
    else
        QMessageBox::critical(this, "Ошибка", QString("Фигура не отрисована."));
}

void MainWindow::on_scaleButton_clicked()
{
    Scale scale = Scale(ui->doubleSpinBoxKX->value(), ui->doubleSpinBoxKY->value());

    if (history.size())
    {
        Fish new_fish = history[history.size() - 1];

        myerror_t rc = scaleFish(new_fish, scale);

        if (rc == ERR_OK)
        {
            history.append(new_fish);
            pointCenter = new_fish.body.center;
            draw();
        }

        if (rc != ERR_OK)
            QMessageBox::critical(this, "Ошибка", QString("Вырожденное масштабирование."));
    }
    else
        QMessageBox::critical(this, "Ошибка", QString("Фигура не отрисована."));
}

void MainWindow::drawAxes(QPainter &p)
{
    int width = WIDTH;
    int height = HEIGHT;

    // Сохраняем текущее состояние painter
    p.save();

    // Переносим начало координат в центр окна
    p.translate(width/2, height/2);

    // Инвертируем ось Y (теперь положительное направление - вверх)
    p.scale(1, -1);

    // Настраиваем перо для рисования
    QPen axisPen(Qt::darkGray);
    axisPen.setWidth(2);
    p.setPen(axisPen);

    // Рассчитываем длину осей (90% от половины размера окна)
    int axisLength = std::min(width, height)/2 * 0.9;

    // Рисуем ось X (горизонтальная линия)
    p.drawLine(-axisLength, 0, axisLength, 0);

    // Рисуем ось Y (вертикальная линия)
    p.drawLine(0, -axisLength, 0, axisLength);

    // Рисуем стрелки
    QBrush brush(Qt::darkGray);
    p.setBrush(brush);

    // Стрелка для оси X
    QPointF xArrow[3] = {
        QPointF(axisLength, 0),
        QPointF(axisLength - 15, 5),
        QPointF(axisLength - 15, -5)
    };
    p.drawPolygon(xArrow, 3);

    // Стрелка для оси Y
    QPointF yArrow[3] = {
        QPointF(0, axisLength),
        QPointF(5, axisLength - 15),
        QPointF(-5, axisLength - 15)
    };
    p.drawPolygon(yArrow, 3);

    // Восстанавливаем преобразования
    p.restore();

    // Подписываем оси (рисуем в нормальных координатах)
    QFont font = p.font();
    font.setPointSize(12);
    p.setFont(font);

    // Подпись оси X
    p.drawText(width/2 + axisLength - 25, height/2 - 10, "X");
    // Подпись оси Y
    p.drawText(width/2 + 10, height/2 - axisLength + 25, "Y");
}

void MainWindow::step_back()
{
    if (history.size())
    {
        history.pop_back();

        if (history.size())
            draw();
        else
            ui->graphicsView->scene()->clear();
    }
    else
    {
        QMessageBox::critical(this, "Ни шагу назад!", QString("Шаг назад невозможен."));
    }
}
