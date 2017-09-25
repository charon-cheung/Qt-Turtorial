#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    String strBuffer;
    QDateTime time;

    strBuffer = "2010-07-02 17:35:00";

    time = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");
}

MainWindow::~MainWindow()
{
    delete ui;
}
