#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "render.h"
#include <QMouseEvent>

#define PIXEL_H 1000
#define PIXEL_W 1000

QColor defineClr(const QString &clrStr);

QImage image(PIXEL_W, PIXEL_H, QImage::Format_ARGB32);

int rows = 0;

QColor fonClr = Qt::white;
QColor edgeClr = Qt::black;
QColor fillClr = Qt::red;

void MainWindow::formEdges()
{
    polygon.clear();

    QPointF prev = points[0];
    
    for (size_t i = 1; i < points.size(); ++i)
    {
        QPointF curr = points[i];

        polygon.append(Edge(prev, curr));
        prev = curr;
    }
    
    if (points.size() > 2)
        polygon.append(Edge(points[0], points[points.size() - 1]));

    points.clear();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QGraphicsScene *scene = new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");
    scene->setSceneRect(0, 0, PIXEL_W, PIXEL_H);
    
    ui->graphicsView->viewport()->installEventFilter(this);
    image.fill(fonClr);

    ui->tableWidgetPoints->setColumnCount(1); 
    ui->tableWidgetPoints->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetPoints->verticalHeader()->setVisible(false);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->graphicsView->viewport() && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        QPointF clickedPos = ui->graphicsView->mapToScene(mouseEvent->pos());
        
        if (mouseEvent->button() == Qt::LeftButton)
        {
            clickedPoints.push_back(clickedPos);
            points.push_back(clickedPos);
            pixelEvent();
        }
        else if (mouseEvent->button() == Qt::RightButton)
        {
            renderingEvent();
        }

        return true;
    }

    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::pixelEvent()
{
    QPointF clicked = clickedPoints[clickedPoints.size() - 1];
    QString line = QString("%1) X = %2; Y = %3").arg(rows).arg(clicked.x()).arg(clicked.y());


    QTableWidgetItem *item = new QTableWidgetItem(line);

    ui->tableWidgetPoints->insertRow(rows);
    ui->tableWidgetPoints->setColumnWidth(rows, 5);
    ui->tableWidgetPoints->setItem(rows, 0, item);
    ++rows;

    QPainter p(&image);
    
    p.setPen(QPen(edgeClr, 1));
    p.drawPoint(clicked);

    QPixmap pixmap = QPixmap::fromImage(image);
    
    ui->graphicsView->scene()->clear();

    ui->graphicsView->scene()->addPixmap(pixmap);
    
    ui->graphicsView->scene()->update();
}

void MainWindow::renderingEvent()
{
    QString strFon = ui->comboBoxFon->currentText();
    QString strFill = ui->comboBoxFill->currentText();
    
    QColor fon = defineClr(strFon);
    QColor fill = defineClr(strFill);

    if (fill == edgeClr)
    {
        return;
    }

    formEdges();
    
    Render rendering;

    if (ui->radioButtonDelay->isChecked())
        rendering = Render(fon, edgeClr, fillClr, true);
    else
        rendering = Render(fon, edgeClr, fillClr, false);

    rendering.renderPolygon(ui->graphicsView->scene(), image, polygon);

    ui->lineEditTime->setText(QString("Время в мс.: %1").arg(rendering.timeRender));
}   


MainWindow::~MainWindow()
{
    delete ui->graphicsView->scene();

    delete ui;
}


QColor defineClr(const QString &clrStr)
{
    if (clrStr == "Красный")
        return Qt::red;
    else if (clrStr == "Зеленый")
        return Qt::GlobalColor::green;
    else if (clrStr == "Синий")
        return Qt::GlobalColor::blue;
    else if (clrStr == "Черный")
        return Qt::GlobalColor::black;
    else if (clrStr == "Белый")
        return Qt::GlobalColor::white;

    return Qt::GlobalColor::white;
}

void MainWindow::on_pushButtonClear_clicked()
{
    for (size_t i = 0; i < rows; ++i)
        delete ui->tableWidgetPoints->item(rows, 0);
    
    rows = 0;

    ui->tableWidgetPoints->clear();
    image.fill(Qt::white);
    
    QPixmap pixmap = QPixmap::fromImage(image);
    
    ui->graphicsView->scene()->clear();

    ui->graphicsView->scene()->addPixmap(pixmap);
    
    ui->graphicsView->scene()->update();
}


void MainWindow::on_pushButtonPoint_clicked()
{
    int x = ui->spinBoxX->value();
    int y = ui->spinBoxY->value();
    
    QPoint point = QPoint(x, y);

    clickedPoints.push_back(point);
    points.push_back(point);
    pixelEvent();
}


void MainWindow::on_pushButtonFigure_clicked()
{
    renderingEvent();
}

