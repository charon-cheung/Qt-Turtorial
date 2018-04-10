#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDebug>
#include <QFileDialog>

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

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_toolButton_clicked()
{
    //NOTE:初始目录必须用斜杠/,否则不识别
    QString dirPath = QFileDialog::getExistingDirectory(0,"open dir","F:/src/src_4ty_test/iPACS5000_application/application");
    QStringList suffixes;
    suffixes<<"h"<<"cpp";
    QStringList files = RecursiveFind(dirPath,suffixes);
    qDebug()<<"文件数:"<<files.count();

    QTime t;
    t.start();
    int count = GetCountBySingleThread(files);
    qDebug()<<"单线程扫描所用的时间:"<<t.elapsed();
    qDebug()<<"单词数: "<<count;
    qDebug()<<"********************************";
    QTime t2;
    t2.start();
    count = GetCountByConcurrent(files);
    qDebug()<<"并发扫描所用的时间:"<<t2.elapsed();
    qDebug()<<"单词数: "<<count;
}
//NOTE:递归搜索某目录下所有的cpp和h文件
QStringList MainWindow::RecursiveFind(QString dirPath,QStringList suffixes)
{
    QStringList names;
    QDir dir;
    dir.setPath(dirPath);
    //NOTE:QDir的Filter枚举，显示所有文件和子目录，除了.和..两个文件夹。
    //NOTE:如果加filter，不能显示子目录
    QFileInfoList infos = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    foreach(QFileInfo info,infos)
    {
        if(info.isDir())
        {
            names += RecursiveFind(info.absoluteFilePath(),suffixes);
        }
        else if(info.isFile())
        {
            if(suffixes.contains(info.suffix()))
            {
                names.append(info.absoluteFilePath());
            }
        }
    }
    return names;
}

unsigned int MainWindow::GetCountBySingleThread(QStringList files)
{
    unsigned int count = 0;
    foreach(QString name,files)
    {
        QFile *file= new QFile(name);
        if(!file->open(QIODevice::ReadOnly))
            return 0;
        QTextStream stream(file);
        while(!stream.atEnd())
        {
            QString line = stream.readLine();
            foreach(QString s,line.split(" "))
            {
                if(!s.isEmpty())
                {
                    count++;
                }
            }
        }
        delete file;
    }
    return count;
}

unsigned int MainWindow::GetCountByConcurrent(QStringList files)
{
    //NOTE:不能用blocking,否则返回的是序列QStringList
    QFuture<unsigned int> future = QtConcurrent::mappedReduced(files,&MainWindow::mappedFile,&MainWindow::reduced);
    return future.result();
}

unsigned int MainWindow::mappedFile(const QString &name)
{
    unsigned int count=0;
    QFile *file= new QFile(name);
    if(!file->open(QIODevice::ReadOnly))
        return 0;
    QTextStream stream(file);
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        foreach(QString s,line.split(" "))
        {
            if(!s.isEmpty())
            {
                count++;
            }
        }
    }
    delete file;
    return count;
}

void MainWindow::reduced(unsigned int &result, const unsigned int &interm)
{
    result+=interm;
    return;
}
