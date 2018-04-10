#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtConcurrent>
#include <QFuture>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_filter_clicked()
{
    ui->list_1->clear();
    ui->list_2->clear();
    QStringList ll;
    ll<<"aa"<<"BB"<<"cc"<<"abCdEFg";
    ui->list_1->addItems(ll);
    //NOTE:两种实现方法，blocking变量,返回最终结果,而不是QFuture
    QStringList ll_2 = QtConcurrent::blockingFiltered(ll,&MainWindow::filter);
    ui->list_2->addItems(ll_2);

//    QtConcurrent::blockingFilter(ll,&MainWindow::filter);
//    ui->list_2->addItems(ll);

    //NOTE:in-place修改，不返回任何结果，无法实现目的
//    QFuture<void> future = QtConcurrent::filter(ll,&MainWindow::filter);
//    ui->list_2->addItems(ll);
    //NOTE:只能返回序列中的第一项，无法实现目的
//    QFuture<QString> future = QtConcurrent::filtered(ll,&MainWindow::filter);
//    ui->list_2->addItem(future.result());
}
//判断字符串中是否有大写字母，若有则抛弃
bool MainWindow::filter(const QString &s)
{
    return s.toLower()==s;
}
