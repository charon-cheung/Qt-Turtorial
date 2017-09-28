#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        /* currentDateTime */
    qDebug()<< QDateTime::currentDateTime().toString(); //"周二 9月 26 08:34:45 2017"
    // the format : "2017-09-26 19:35:46 周二"
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    qDebug()<< QDateTime::currentDateTimeUtc().toString();  //"周二 9月 26 00:34:45 2017 GMT"

    QString str = "2012-07-02 17:35:00";
    QDateTime time = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
    //output: QDateTime(2012-07-02 17:35:00.000 中国标准时间 Qt::TimeSpec(LocalTime))
    // 格式必须对应
    qDebug()<<"time is "<< time;
    time.setTime_t(0);      // set the time since UTC time, parameter is seconds
    qDebug()<<"new time is "<< time;
    qDebug()<< "Epoch time:"<<time.toSecsSinceEpoch();     // seconds elapsed since 1970-1-1-00:00:00
    QDateTime newDate = time.addYears(5);   // time doesn't change
    qDebug()<<"new date:"<<newDate.toString();

        /* QDate */
    bool leap = QDate::isLeapYear(2000); // leap year has 366 days


    /*  QTime  */
    QTime t;
    qDebug()<<t.currentTime().toString();   // "19:39:31"
    // return hour, minute, second
    int hour = t.currentTime().hour();
    int minute = t.currentTime().hour();
    int sec = t.currentTime().second();

    t.setHMS(10,20,80);
    qDebug()<<t.toString();     // "10:20:30"

    // use start() and elapsed() to timing
    t.start();
    int a=0;
    for(int i=0; i<100000000;i++)
        a+=i;
    qDebug()<<"time elapsed:"<<t.elapsed()<<" ms";      // 275 ms
}

MainWindow::~MainWindow()
{
    delete ui;
}
