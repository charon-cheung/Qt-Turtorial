#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new Dialog(this);
    d->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getValue(QString t)
{
    ui->label->setText(t);
}
