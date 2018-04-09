#include "myjob.h"

MyJob::MyJob()
{
    m_stop = false;
}

void MyJob::start(QString name)
{
    m_stop = false;
    for(int i=0;i<999999;i++)
    {
        if(m_stop)
            return;
        qDebug()<<"From thread: "<<i;
        emit On_Number(name,i);
        QThread::currentThread()->msleep(100);
    }
}

void MyJob::stop()
{
    m_stop = true;
}
