#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QThread>
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
        QThreadPool::globalInstance()->start(t,QThread::LowestPriority);
        Task *t2 = new Task(2,this);
        QThreadPool::globalInstance()->start(t2,QThread::HighPriority);
        Task *t3 = new Task(3,this);
        QThreadPool::globalInstance()->start(t3,QThread::HighestPriority);
//        pool.start(t);
//        connect(t,SIGNAL(toLine(QString)),this,SLOT(appendText(QString)));
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
