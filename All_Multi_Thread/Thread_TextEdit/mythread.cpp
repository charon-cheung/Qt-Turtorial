#include "mythread.h"

// 利用了构造函数传参数，否则难以在主线程添加文本
MyThread::MyThread(QTextEdit *edit)
{
//    构造函数在GUI线程创建，实际线程ID还是GUI线程的
    m_edit = edit;
    m_stop = false;
    qRegisterMetaType<QTextCursor>("QTextCursor");
    QString path = "E:/qtgui.index";
    file = new QFile(path);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Open Failed !";
}

void MyThread::stop()
{
    m_stop = true;
}

void MyThread::run()
{
//    子线程的ID只能在这里获得
    qDebug()<<"child id:"<<QThread::currentThreadId();
    QTextStream in(file);
    while(!in.atEnd() && !m_stop)
    {
        QString line = in.readLine();
//        方法一
        QMetaObject::invokeMethod(m_edit, "append", Q_ARG(QString, line));
        /* 每读取一行就会让 UI 线程执行一个更新界面的操作，qtgui.index 有18.5万行，
        导致 UI 线程更新界面的操作太多，非常消耗资源，导致 UI 忙不过来被阻塞。
        为了减少UI 线程更新界面的频率，读取一行后暂停  */
        QThread::msleep(5);     // 参数调大，主线程越流畅
//        qDebug()<<line;
    }
}
