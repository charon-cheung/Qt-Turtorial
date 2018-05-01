#include "mainwindow.h"
#include "ui_mainwindow.h"

// ��ȫ�ֱ��������ܷ���ͷ�ļ�
const int DataSize = 10;
const int BufferSize = 3;
QList<int> buffer;
QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QString& aa="aa";
    QString const& bb = "bb";
    t1 = new Thread_1();
    t2 = new Thread_2();
    connect(t2, SIGNAL(MsgSig(int)),this,SLOT(ShowMsg(int)),Qt::QueuedConnection);
    t1->start();
    t2->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    buffer.empty();
}

Thread_1::Thread_1()
{
    stop_1 = false;
}

Thread_1::~Thread_1()
{

}

void Thread_1::stop()
{
    stop_1 = true;
}

void Thread_1::run()
{
    while(!stop_1)
    {
        QThread::sleep(1);
//        qDebug()<<"thread 1:"<<qrand()%100;
        num = qrand()%100;
        qDebug()<<"thread 1:"<<num;
        freeBytes.acquire();
        buffer.append(num);     // ���BufferSize�������޷���д�룬�߳�1��ס��
                                // ��ʱ�����߳�2�����ȡbuffer�е����ݣ�Ȼ���߳�1���Լ�������
        qDebug()<<"thread 1:"<<buffer;
        usedBytes.release();
    }
}

Thread_2::Thread_2()
{
    stop_2 = false;
}

Thread_2::~Thread_2()
{

}

void Thread_2::stop()
{
    stop_2 = true;
}

void Thread_2::run()
{
    while(!stop_2)
    {
        QThread::sleep(2);
        usedBytes.acquire();
        qDebug()<<"thread 2:"<<buffer;
        int size = buffer.size();
        emit MsgSig(buffer.at(size-1));
        freeBytes.release();
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(t1->isRunning())
        t1->stop();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(t2->isRunning())
        t2->stop();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(!t1->isRunning())
        t1->start();
}

void MainWindow::on_pushButton_4_clicked()
{
    if(!t2->isRunning())
        t2->start();
}

void MainWindow::on_pushButton_5_clicked()
{
    buffer.empty();
}

void MainWindow::ShowMsg(int value)
{
    ui->label->setText(QString::number(value));
}
