#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDateTime>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _QDateTime();
    _QDate();
    _QTimeZone();
    _QTime();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_QDateTime()
{
    qDebug()<<"-----------------_QDateTime()-----------------";
    qDebug()<< QDateTime::currentDateTime().toString(); //"周二 9月 26 08:34:45 2017"
    // the format : "2017-09-26 19:35:46 周二"
    qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    qDebug()<< QDateTime::currentDateTimeUtc().toString();  //"周二 9月 26 00:34:45 2017 GMT"

    QString str = "2012-07-02 17:35:00";
    QDateTime time = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
    //output: QDateTime(2012-07-02 17:35:00.000 中国标准时间 Qt::TimeSpec(LocalTime))
    // 格式必须对应
    qDebug()<<"time is "<< time;
    qDebug()<<"time since UTC:"<<time.toTime_t();
    time.setTime_t(0);      // set the time since UTC time, parameter is seconds
    qDebug()<<"new time is "<< time;
    qDebug()<< "Epoch time:"<<time.toSecsSinceEpoch();     // seconds elapsed since 1970-1-1-00:00:00
    QDateTime newDate = time.addYears(5);   // time doesn't change
    qDebug()<<"new date:"<<newDate.toString();
}

void MainWindow::_QDate()
{
    qDebug()<<"-----------------_QDate()-----------------";
    bool leap = QDate::isLeapYear(2000); // whether 2000 is a leap year, which has 366 days
    if(leap)
        qDebug()<<"This year has 366 days";
}

void MainWindow::_QTimeZone()
{
    qDebug()<<"-----------------_QTimeZone()-----------------";
    QDateTime current = QDateTime::currentDateTime();
    qDebug()<<current.timeZoneAbbreviation();       // current time zone's name
    int LOCAL_TIME_ZONE = 24 - QDateTime(QDate(1970,1,2), QTime(0,0,0), Qt::LocalTime).toTime_t() / 3600;
    qDebug() << LOCAL_TIME_ZONE;    // current time zone's  id, Beijing is 8
}

void MainWindow::_QTime()
{
    qDebug()<<"-----------------_QTime()-----------------";
    QTime t;
    qDebug()<<t.currentTime().toString();   // "19:39:31"
    // return current hour, minute, second
    qDebug()<< t.currentTime().hour();
    qDebug()<< t.currentTime().hour();
    qDebug()<< t.currentTime().second();

    t.setHMS(10,20,80);
    qDebug()<<t.toString();     // "10:20:30"

    // use start() and elapsed() to timing
    t.start();
    int a=0;
    for(int i=0; i<100000000;i++)
        a+=i;
    qDebug()<<"time elapsed:"<<t.elapsed()<<" ms";      // 275 ms
}

bool MainWindow::hasFeb29(QDateTime min, QDateTime max)
{
    if(max.toTime_t()<min.toTime_t())
        return false;
    int minYear = min.date().year();
    int maxYear = max.date().year();

    if(minYear == maxYear)
    {
        if(!QDate::isLeapYear(minYear))     // 平年
            return false;
        else
        {
            if(max.secsTo(QDateTime(QDate(minYear,2,29),QTime(0,0,0))) >=0 || min.secsTo(QDateTime(QDate(minYear,3,1),QTime(0,0,0))) <=0)
                return false;
            else
                return true;
        }
    }
    else
    {
        if(!QDate::isLeapYear(minYear) && !QDate::isLeapYear(maxYear))
        {
            int n = maxYear - minYear;
            for(int a=minYear+1; a<minYear+n; a++)
            {
                if(QDate::isLeapYear(a))
                {
                    return true;
                }
            }
        }
        else if(!QDate::isLeapYear(minYear) &&  QDate::isLeapYear(maxYear))
        {
            if(max.secsTo(QDateTime(QDate(maxYear,2,29),QTime(0,0,0)))<0 )
                return true;
            else return false;
        }
        else if(QDate::isLeapYear(minYear) && !QDate::isLeapYear(maxYear))
        {
            if(min.secsTo(QDateTime(QDate(minYear,3,1),QTime(0,0,0)))>0 )
                return true;
            else return false;
        }
        else if(QDate::isLeapYear(minYear) && QDate::isLeapYear(maxYear))
        {
            if(max.secsTo(QDateTime(QDate(maxYear,2,29),QTime(0,0,0)))>0 && min.secsTo(QDateTime(QDate(minYear,3,1),QTime(0,0,0)))<=0)
                return false;
            else return true;
        }
    }
}

void MainWindow::on_btn_clicked()
{
    qDebug()<< hasFeb29(ui->min->dateTime(), ui->max->dateTime())<<qrand()%100;
}
