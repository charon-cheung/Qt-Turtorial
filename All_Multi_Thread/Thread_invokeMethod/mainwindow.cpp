#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMetaType>
#include <QMetaMethod>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    QMetaObject::invokeMethod()

    ui->setupUi(this);
    ui->label->setFont(QFont("Inconsolata",30));
    qDebug()<<"ui thread:"<<QThread::currentThreadId();
    thread = new XThread();
    thread->start();
//    connect(thread,&XThread::currentTime,this,&MainWindow::ShowTime);

    connect(thread, &XThread::currentTime, [this](const QString &time) {

        qDebug() << "connect:  " << QThread::currentThread(); // 当前环境的上下文属于线程 XThread
//        this->ShowTime(time); // Error: 有时候没问题，有时候会有警告，有的时候程序直接退出，所以不要这么做，相当于在 XThread 中直接调用
        QMetaObject::invokeMethod(this, "ShowTime", Q_ARG(QString, time)); // OK: 一个线程调中用另外一个线程中函数的正确姿势
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowTime(QString time)
{
    if(thread->isRunning())
        qDebug()<<"thread in ShowTime:"<<QThread::currentThreadId();
    ui->label->setText(time);
}
