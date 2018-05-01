#include "myobj.h"

MyObj::MyObj()
{
    m_stop = true;
}

void MyObj::doWork()
{
    qDebug()<<"timer thread:"<<QThread::currentThread();
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(testTimer()));
    timer->start(2000);
}

void MyObj::testTimer()
{
    QString str = QString::number(qrand()%100);
    qDebug()<<"test timer:"<<str;
    emit toLine(str);
}

void MyObj::Stop()
{
    m_stop = false;
}
