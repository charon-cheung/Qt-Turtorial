#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QProgressDialog>

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

void MainWindow::on_ColorDialog_clicked()
{
    QColor color = QColorDialog::getColor(Qt::yellow, 0, "I'm title");
    ui->ColorDialog->setPalette(QPalette(color));
}

void MainWindow::on_QInputDialog_clicked()
{

}
