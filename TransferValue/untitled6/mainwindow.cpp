#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new Dialog();
    d->show();
    connect(d, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveData(QString data)
{
    ui->label->setText(data);
}
