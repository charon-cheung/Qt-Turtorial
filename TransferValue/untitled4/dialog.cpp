#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("dialog");
    m = qobject_cast<MainWindow*>(parent);
}

Dialog::Dialog(MainWindow *parent) :
        QDialog(parent),
        ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("dialog");
    m = parent;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString value = ui->lineEdit->text();
    m->getValue(value);
}
