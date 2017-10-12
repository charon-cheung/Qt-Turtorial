#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QProgressDialog>
#include <QWizard>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    float a=9;
    int b=20;
    float c = a/b;
    qDebug()<<c;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ColorDialog_clicked()
{
    QColor color = QColorDialog::getColor(Qt::yellow, 0, "I'm title");
    qDebug()<<color;
}

void MainWindow::on_QInputDialog_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("User name:"), QLineEdit::Normal,
                                         QDir::home().dirName(),    // user directory
                                         &ok);
    if (ok && !text.isEmpty())
        qDebug()<<"input text: "<<text;
}

void MainWindow::on_QFontDialog_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    qDebug()<<font;
}

void MainWindow::on_QProgressDialog_clicked()
{
    QProgressDialog *proDlg = new QProgressDialog(("Saving......"),"Cancel",0,100,this);
    proDlg->setWindowModality(Qt::WindowModal);
    proDlg->setModal(true);
    proDlg->setWindowTitle("Please Wait");
    proDlg->setMinimumDuration(1);
    proDlg->setValue(10);
    for(int i=0;i<=10000000;i++)
   {
       qDebug()<<"setvalue i = "<<i;
       for(int j=0;j<20000;j++);
       proDlg->setValue(i);
       if(proDlg->wasCanceled())//ºÏ≤‚ «∑Ò»°œ˚
       {
           delete proDlg;
           qDebug("stop set value");
           break;
       }
   }
}

void MainWindow::on_QWizard_clicked()
{

}

void MainWindow::on_QFileDialog_clicked()
{

}
