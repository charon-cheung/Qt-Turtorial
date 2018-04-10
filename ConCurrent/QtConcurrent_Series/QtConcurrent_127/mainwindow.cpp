#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_1->clear();
    ui->widget_2->clear();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::filter(const QString &s)
{
    return s.toLower()==s;
}

void MainWindow::reduced(QStringList &list, const QString &s)
{
    list.append(s);
}


void MainWindow::on_btn_clicked()
{
    QStringList list;
    list<<"bob"<<"James"<<"michael"<<"jane"<<"Donald"<<"Ted";
    ui->widget_1->addItems(list);
    QFuture<QStringList> future = QtConcurrent::filteredReduced(list,&MainWindow::filter,&MainWindow::reduced);
    watcher.setFuture(future);
    connect(&watcher,SIGNAL(started()),this,SLOT(start()));
    connect(&watcher,SIGNAL(finished()),this,SLOT(finish()));
    connect(&watcher,SIGNAL(progressRangeChanged(int,int)),this,SLOT(rangeChanged()));
    connect(&watcher,SIGNAL(progressValueChanged(int)),this,SLOT(valueChange()));
    future.waitForFinished();

    ui->widget_2->addItems(future.result());
    qDebug()<<"list:"<<list;    //NOTE:list未变
}
