#include "xthread.h"
#include <QTime>
#include <QDateTime>
#include <QDebug>
XThread::XThread()
{
}

void XThread::run()
{
    while(1)
    {
        qDebug()<<"XThread:"<<QThread::currentThreadId();
        emit currentTime(QTime::currentTime().toString("hh:mm:ss"));
    }
}
