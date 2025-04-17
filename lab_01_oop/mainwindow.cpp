#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFileDialog"

#include "handler.h"

userRequest_t request;

#define WIDTH 500
#define HEIGHT 300

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);
    ui->graphicsView->scale(1,-1);
    ui->lineEdit_7->setReadOnly(true);
    ui->lineEdit_10->setReadOnly(true);
    ui->lineEdit_9->setReadOnly(true);
    ui->lineEdit_8->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineMove->setReadOnly(true);
    ui->lineEdit_11->setReadOnly(true);
    ui->lineEdit_12->setReadOnly(true);
    ui->editDx->setReadOnly(true);
    ui->editDy->setReadOnly(true);
    ui->editDz->setReadOnly(true);

    connect(ui->action_3, &QAction::triggered, this,
            &MainWindow::on_actionLoad_clicked);

    connect(ui->action_4, &QAction::triggered, this,
            &MainWindow::exitApp);

    ui->doubleSpinBoxAx->setRange(-180, 180);
    ui->doubleSpinBoxAy->setRange(-180, 180);
    ui->doubleSpinBoxAz->setRange(-180, 180);

    ui->doubleSpinBoxDx->setRange(-500, 500);
    ui->doubleSpinBoxDy->setRange(-500, 500);
    ui->doubleSpinBoxDz->setRange(-500, 500);

    ui->doubleSpinBoxKx->setRange(-5, 5);
    ui->doubleSpinBoxKy->setRange(-5, 5);
    ui->doubleSpinBoxKz->setRange(-5, 5);
}

void MainWindow::exitApp()
{
    request.action = QUIT;

    QApplication::quit();
}

MainWindow::~MainWindow()
{
    userRequest_t request;
    request.action = QUIT;
    handler(request);

    delete ui;
}

myerror_t MainWindow::draw_on_scene()
{
    request.action = ACTION_DRAW_FIGURE;
    request.scene.scene = ui->graphicsView->scene();

    request.scene.height = HEIGHT;
    request.scene.width = WIDTH;
    return handler(request);
}

myerror_t MainWindow::on_actionLoad_clicked()
{
    QString path = QFileDialog::getOpenFileName();

    std::string file = path.toUtf8().toStdString();

    const char *f = file.c_str();

    request.action = ACTION_LOAD_FIGURE;

    request.filename = (char *) f;

    myerror_t rc = handler(request);

    if (rc == ERR_OK)
    {
        rc = draw_on_scene();
    }

    if (rc != ERR_OK)
    {
        error_message(rc);
    }

    return rc;
}

myerror_t MainWindow::on_move_clicked()
{
    request.action = ACTION_MOVE_FIGURE;
    double dx = ui->doubleSpinBoxDx->value();
    double dy = ui->doubleSpinBoxDy->value();
    double dz = ui->doubleSpinBoxDz->value();

    request.vector = initVec(dx, dy, dz);

    myerror_t rc = handler(request);

    if (rc == ERR_OK)
    {
        rc = draw_on_scene();
    }

    if (rc != ERR_OK)
    {
        error_message(rc);
    }

    return rc;
}

myerror_t MainWindow::on_scale_clicked()
{
    request.action = ACTION_SCALE_FIGURE;
    double kx = ui->doubleSpinBoxKx->value();
    double ky = ui->doubleSpinBoxKy->value();
    double kz = ui->doubleSpinBoxKz->value();
    request.scale = initScale(kx, ky, kz);

    myerror_t rc = handler(request);

    if (rc == ERR_OK)
    {
        rc = draw_on_scene();
    }

    if (rc != ERR_OK)
    {
        error_message(rc);
    }

    return rc;
}

myerror_t MainWindow::on_rotate_clicked()
{
    request.action = ACTION_ROTATE_FIGURE;
    double angleX = ui->doubleSpinBoxAx->value() * M_PI / 180;
    double angleY = ui->doubleSpinBoxAy->value() * M_PI / 180;
    double angleZ = ui->doubleSpinBoxAz->value() * M_PI / 180;
    request.rotate = initRotate(angleX, angleY, angleZ);

    myerror_t rc = handler(request);

    if (rc == ERR_OK)
    {
        rc = draw_on_scene();
    }

    if (rc != ERR_OK)
    {
        error_message(rc);
    }

    return rc;
}

void MainWindow::error_message(myerror_t &rc)
{
    switch (rc)
    {
    case ERR_DRAW_SCENE:
        QMessageBox::critical(this, "Ошибка", "Ошибка отрисовки");
        break;
    case ERR_RANGE_INDEXES:
        QMessageBox::critical(this, "Ошибка", "Ошибка выхода за границы");
        break;
    case ERR_ALLOCATION:
        QMessageBox::critical(this, "Ошибка", "Ошибка выделения памяти");
        break;
    case ERR_INPUT_DATA:
        QMessageBox::critical(this, "Ошибка", "Ошибка чтения данных");
        break;
    case ERR_INITIALIZATION:
        QMessageBox::critical(this, "Ошибка", "Ошибка инициализации");
        break;
    case ERR_DEFINED_COMMAND:
        QMessageBox::critical(this, "Ошибка", "Неизвестный код ошибки");
        break;
    case ERR_NULLPTR_ARRAY:
        QMessageBox::critical(this, "Ошибка", "Нулевой указатель массива");
        break;
    case ERR_MEM_BUSY:
        QMessageBox::critical(this, "Ошибка", "Память занята");
    case ERR_OK:
        break;
    }
}
