#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"main id:"<<QThread::currentThreadId();
    thread = new MyThread(ui->textEdit);
    thread->start();
    //方法二
//    connect(thread,SIGNAL(TransferMsg(QString)),this,SLOT(ShowMsg(QString)));
//    connect(thread,SIGNAL(finished()),this,SLOT(FinishThread()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//不用多线程，手动强制进行UI事件循环的方法，处理所有事件队列中的事件并返回给调用者。
void MainWindow::on_ReadBtn_clicked()
{
//    while 循环结束后才执行 UI 事件队列中的update函数更新界面,导致我们看到界面被冻住，
//    读取完文件后一次性显示出所有内容
    QString path = "E:/qtgui.index";
    file = new QFile(path);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Open Failed !";
    QTextStream in(file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        ui->textEdit->append(line);
        QApplication::processEvents();
    }
}

void MainWindow::FinishThread()
{
    qDebug()<<"thread finished !";
}

void MainWindow::on_pushButton_clicked()
{
    /* terminate() 结束线程是非常危险的，它可能
    在run()中的任意地方结束，可能导致死锁、资源没有释放等*/
    thread->stop();
    thread->wait();     //等待线程真正的结束执行

    /*  因为调用 stop() 后需要等一下 ReadingThread
    才能得到执行权限，然后循环结束，等到 run() 结束
    返回时需要一点时间,期间可能出意外，高并发的情况下更是不可预料
    */
}

void MainWindow::ShowMsg(QString text)
{
    ui->textEdit->append(text);
}
