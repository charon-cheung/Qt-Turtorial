#include "mainwindow.h"
#include <QApplication>
void swap(int& x, int& y)
{
   int temp;
   temp = x; /* 保存地址 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y  */
   return;
}
void foo_r(int& num)
{
    for(int i=0;i<10;i++)
        num++;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int b=9,c=20;
//    int &c=b;
    swap(b,c);
//    qDebug()<<"b:"<<b;
//    qDebug()<<"c:"<<c;
//    foo_r(c);
//    qDebug()<<"b:"<<b;
//    qDebug()<<"c:"<<c;
    return a.exec();
}
