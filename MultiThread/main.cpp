#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Thread_1* t1 = new Thread_1();
//    Thread_2* t2 = new Thread_2();
//    t1->start();
//    t2->start();
    MainWindow w;
    w.show();
    return a.exec();
}
