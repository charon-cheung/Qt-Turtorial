#include "task.h"
#include <QDebug>

Task::Task(int id,QWidget* w):
    m_id(id),
    m_w(w)
{

}

void Task::run()
{
    QFile* file = new QFile("E:\qtgui.index");
    file->open(QIODevice::ReadOnly);
    QTextStream *stream = new QTextStream(file);
    qDebug()<<"do work's thread:"<<QThread::currentThread();
    while(!stream->atEnd())
    {
        QString line = stream->readLine();
//        qDebug()<<line;
        emit toLine(line);
//        QMetaObject::invokeMethod(m_w,"appendText",Qt::AutoConnection,Q_ARG(QString,line));
        QThread::msleep(15);
    }
}

Task::~Task()
{
    qDebug().noquote() << QString("deconstruct  Task with ID %1").arg(m_id);
}
