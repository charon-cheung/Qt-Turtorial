#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    t = new Test(this);
    t->output();
//    QMetaObject::invokeMethod(t,"output",Qt::QueuedConnection,Q_ARG(int,num));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_on_log(QString strtemp)
{
    qDebug()<<strtemp;
}
