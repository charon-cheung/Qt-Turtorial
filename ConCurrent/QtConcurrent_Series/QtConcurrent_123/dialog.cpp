#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QtConcurrent>
#include <QTime>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::Random(int &num)
{
    int a = qrand()%100;
    num = a;
    return 0;
}

int Dialog::Randomed(const int& num)
{
    int a = qrand()%100;
//    num = a;
    return 0;
}

int map(int &num)   //map函数声明形式：U function(T &t);
{
    int a = qrand()%100;
    num = a;
    return 0;
}

int mapped(const int& num)  //mapped函数声明形式：U function(const T &t);
{
//    int a = qrand()%100;
//    num = a;
    return 0;
}

void Dialog::on_pushButton_clicked()
{
    QList<int> list;
    for(int i=0; i<100000; i++)
    {
        list.append(i);
    }
    //NOTE:第二个参数应当是FunctionWrapper1<int,int&>,如果成员函数Random不是静态的,类型变为<int,Dialog,int&>
    //NOTE:或者用非成员函数rrr   
    QFuture<void> f = QtConcurrent::map(list,&Dialog::Random);  //第二个参数或者用map函数
//    QFuture<int> fed = QtConcurrent::mapped(list,&Dialog::Randomed);    //第二个参数或者用mapped函数

//    QtConcurrent::blockingMap(list,&Dialog::Random);
//    QtConcurrent::blockingMap(list,map);
//    QList<int> future = QtConcurrent::blockingMapped(list,mapped);  //第二个参数或者用&Dialog::Randomed
    ui->listWidget->clear();
    for(int i=0; i<list.count(); i++)
    {
        ui->listWidget->addItem(QString::number(list.at(i)));
    }
}
