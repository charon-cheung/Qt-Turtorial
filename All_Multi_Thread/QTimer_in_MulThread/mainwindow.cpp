#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    t = new QThread();
    obj = new MyObj();
    obj->moveToThread(t);
    qDebug()<<"main thread:"<<QThread::currentThread();
    connect(t,SIGNAL(started()), obj, SLOT(doWork()), Qt::QueuedConnection);
    connect(obj,SIGNAL(toLine(QString)),this,SLOT(appendText(QString) ),Qt::QueuedConnection );
    connect(t,SIGNAL(finished()), obj, SLOT(deleteLater()) );
    t->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug()<<"deconstruct";
    t->quit();
    t->wait();
}

void MainWindow::appendText(QString lineTemp)
{
    qDebug()<<"append Text's thread:"<<QThread::currentThread();
    ui->textEdit->append(lineTemp);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    qDebug()<<"closeEvent";
    emit closeMe();
    QMainWindow::closeEvent(e);
}

void MainWindow::on_pushButton_clicked()
{
    obj->Stop();
    t->quit();
    t->wait();
}
