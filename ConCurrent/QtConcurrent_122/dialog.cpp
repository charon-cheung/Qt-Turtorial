#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_job = new MyJob();

    connect(&watcher,SIGNAL(finished()),this,SLOT(NotifyFinished()));
}

Dialog::~Dialog()
{
    delete ui;
    m_job->stop();    // 不加，则关闭窗口后线程仍在运行
    delete m_job;
}

void Dialog::on_start_clicked()
{
    connect(m_job,&MyJob::On_Number,this,&Dialog::New_Num);
//    connect(this,&Dialog::on_Stop,m_job,&MyJob::stop);
//    run用另一个线程运行一个函数, 可以是任意数量的任意类型参数；QFuture获取异步计算结果
    //QFuture的模板类型应与运行的函数类型一致
    QFuture<void> test = QtConcurrent::run(this->m_job,&MyJob::start,QString("My Thread"));
    watcher.setFuture(test);
}

void Dialog::on_stop_clicked()
{
//    emit on_Stop();
    m_job->stop();
}

void Dialog::New_Num(QString name, int num)
{
    qDebug()<<"from dialog: "<<name<<"  "<<num;
    ui->lineEdit->setText(name+"  "+QString::number(num));
}

void Dialog::NotifyFinished()
{
    qDebug()<<"thread finished !";
}
