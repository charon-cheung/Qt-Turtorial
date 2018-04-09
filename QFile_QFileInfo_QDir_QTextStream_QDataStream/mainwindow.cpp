#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QDateTime>
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filePath.clear();
    ui->rename->setEnabled(false);
    ui->entryInfo->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_file_clicked()
{
    filePath = QFileDialog::getOpenFileName(this,"Open File","D:/");
    file.setFileName(filePath);
    fInfo.setFile(file);
    if(!filePath.isEmpty() && file.exists())
        ui->rename->setEnabled(true);
    qDebug()<<"abs file path:"<<fInfo.absoluteFilePath();
    qDebug()<<"abs path:"<<fInfo.absolutePath();
    qDebug()<<"file created time:"<<fInfo.created().toString();
    qDebug()<<"file name:"<<fInfo.fileName();
    qDebug()<<"file base name:"<<fInfo.baseName();
    qDebug()<<"file suffix:"<<fInfo.suffix();
}

void MainWindow::on_open_dir_clicked()
{
    dirPath = QFileDialog::getExistingDirectory(this,"Open File","D:/");
    dir.setPath(dirPath);
    if(!dirPath.isEmpty())
        ui->entryInfo->setEnabled(true);
}

void MainWindow::on_rename_clicked()
{
    if(filePath.isEmpty() || !file.exists())
        return;
    QString newName = QInputDialog::getText(this,"Input new name","name",QLineEdit::Normal,
                                            "Input");
//  用rename(const QString &newName);会将文件移到build文件夹; 常用以下两种方法
    bool ret = QFile::rename(fInfo.absoluteFilePath(),fInfo.absolutePath()+"/"+newName+"."+fInfo.suffix());
//    bool ret = dir.rename(fInfo.absoluteFilePath(),fInfo.absolutePath()+"/"+newName+"."+fInfo.suffix());
    if(!ret)
        qDebug()<<"重命名失败!";
}

void MainWindow::on_entryInfo_clicked()
{
    if(dirPath.isEmpty() || !dir.exists())
        return;
    dir.setCurrent(dirPath);
    qDebug()<<"current path"<<dir.currentPath();
    qDebug()<<"All the entry:"<<dir.entryList();  // 所有文件和文件夹的名称
    QStringList filter;
    filter<<"*.exe";
    qDebug()<<"All the exe:"<<dir.entryInfoList(filter);  // 所有exe文件的QFileInfo
    dir.mkdir("New_Dir");       // bool
    dir.cd("New_Dir");          // bool,改变QDir::path()
    qDebug()<<"current path"<<dir.path();
    dir.cd("..");               // 返回上一层
    dir.rmdir("New_Dir");       // 删除New_Dir文件夹
}

void MainWindow::on_readFile_clicked()
{
    if(filePath.isEmpty() || !file.exists())
        return;
    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"Open file failed !";
    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        qDebug()<<stream.readLine();
    }

}
