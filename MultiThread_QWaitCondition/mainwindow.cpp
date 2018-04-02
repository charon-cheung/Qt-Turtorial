#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMetaType>

const int DataSize = 50;
const int BufferSize = 5;
QList<int> buffer;
QWaitCondition BufferNotEmpty;
QWaitCondition BufferNotFull;
int ProducedBytes = 0;
QMutex mutex;   // 最好用全局变量，不要在两个线程各定义局部变量

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Thread_1* producer = new Thread_1();
    Thread_2* consumer = new Thread_2();
    connect(consumer,SIGNAL(SendData(QList<int>)),this,SLOT(SetLastBufferNum(QList<int>)));

    producer->start();
    consumer->start();
    producer->wait();
    consumer->wait();
}

MainWindow::~MainWindow()
{
    delete ui;
    buffer.clear();
}

void MainWindow::SetLastBufferNum(QList<int> buffer)
{
    int num = buffer.at(buffer.size()-1);
    ui->label->setText(QString::number(num));
}

Thread_1::Thread_1()
{

}

Thread_1::~Thread_1()
{

}

void Thread_1::run()
{
    for(int i=0;i<DataSize;i++)
    {
        mutex.lock();
        if(ProducedBytes== BufferSize)  //判断是否满,因为缓冲区空或不为空(但不满)都应写入
            BufferNotFull.wait(&mutex);     // 已经满,所以不满的线程阻塞
        int num = qrand()%100;
        buffer.append(num);
        qDebug()<<"producer buffer:"<<buffer;
        ProducedBytes++;
        BufferNotEmpty.wakeAll();   //缓冲区有数据,唤醒消费者线程
        mutex.unlock();
    }
}

Thread_2::Thread_2()
{
    qRegisterMetaType<QList<int>>("QList<int>");
}

Thread_2::~Thread_2()
{

}

void Thread_2::run()
{
    for(int i=0;i<DataSize;i++)
    {
        mutex.lock();
        if(ProducedBytes==0)    // 缓冲区为空则不能读取数据
            BufferNotEmpty.wait(&mutex);
        qDebug()<<"consumer buffer:"<<buffer;
        SendData(buffer);
        ProducedBytes--;
        BufferNotFull.wakeAll();    // 缓冲区不满，可以继续写数据了
        mutex.unlock();
    }
}
