#include <QApplication>
#include <QObjectCleanupHandler>
#include <QPushButton>
#include <QDebug>
#include "mainwindow.h"
#include "test.h"
int main(int argc, char* argv[])
{
   QApplication app(argc, argv);
   MainWindow m;
   m.show();
   Test t;
   t.setNum(17);
   qDebug()<<t.getNum();
   return app.exec();
}
