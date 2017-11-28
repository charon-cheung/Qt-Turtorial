#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()!= Qt::LeftButton)
        return;
    startTopLeft = this->pos();
    startPos = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    movePos = event->globalPos();
    int X = movePos.x() - startPos.x();
    int Y = movePos.y() - startPos.y();
    this->move(startTopLeft.x() + X, startTopLeft.y()+Y);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::LeftButton)
        return;
}
