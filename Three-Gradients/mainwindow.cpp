#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 封闭图形用QBrush渐变
void MainWindow::DrawLinearBrush(QPainter painter)
{
//    QLinearGradient构造函数有四个参数，分别是x1, y1, x2, y2，即渐变的起始点和终止点
    QLinearGradient linearGradient(100, 100, 200, 200);
    linearGradient.setColorAt(0.0, Qt::white);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1.0, Qt::black);
    painter.setBrush(QBrush(linearGradient));
    painter.drawRect(50, 50, 200, 200);
}

// 直线也可以渐变
void MainWindow::DrawLinearPen(QPainter painter)
{
    QLinearGradient linear(300, 100, 400, 200);
    linear.setColorAt(0.0, Qt::yellow);
    linear.setColorAt(0.5, Qt::red);
    linear.setColorAt(1.0, Qt::black);
    painter.setPen(QPen(QBrush(linear), 6));
    painter.drawLine(300, 100, 400, 200);
}
// 辐射渐变
void MainWindow::DrawRadialBrush(QPainter painter)
{
    qreal radius = 100;    // 半径
    QPointF center(150, 400);  // 圆心
    QPointF focus(150, 400); // 焦点
    QRadialGradient radial(center, radius, focus);
    radial.setColorAt(0, Qt::yellow);
    radial.setColorAt(0.5, Qt::white);
    radial.setColorAt(1, Qt::black);
    painter.setBrush(QBrush(radial));
    painter.setPen(QPen(Qt::black));
    painter.drawEllipse(QPoint(150,400),100,100);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing, true);

    DrawLinearBrush(painter);
    DrawLinearPen(painter);
    DrawRadialBrush(painter);

}
