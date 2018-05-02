#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QThreadPool pool;
    pool.setMaxThreadCount(1);
//    for(int i=0;i<15;i++)
    {
        Task *t = new Task(1,this);
        QThreadPool::globalInstance()->start(t);
//        pool.start(t);
        connect(t,SIGNAL(toLine(QString)),this,SLOT(appendText(QString)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendText(QString text)
{
    qDebug()<<"append text";
    ui->textEdit->append(text);
}
