#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString pattern = "Time: %{time mm:ss:zzz}  %{message}  %{function} ";
    qSetMessagePattern(pattern);
    qDebug()<<"main id:"<<QThread::currentThreadId();
    return a.exec();
}
