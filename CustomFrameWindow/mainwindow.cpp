#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pressed = false;
    this->setWindowFlag(Qt::FramelessWindowHint);
    width = this->geometry().width();
    ui->close->move(width-45,0);
    ui->max->move(width-90,0);
    ui->min->move(width-135,0);
    QDesktopWidget* desk = QApplication::desktop();
    windowWidth = desk->screenGeometry().width();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//自定义边框栏
void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter* p = new QPainter(this);
    if(windowState() & Qt::WindowMaximized || windowState() & Qt::WindowFullScreen)
    {
        p->setBrush(QBrush(QColor(255,255,255)));
        p->drawRect(QRect(0,0,windowWidth,45));
        p->setPen(QColor(240,240,240));
        p->drawLine(QLine(QPoint(0,45),QPoint(windowWidth,45)));
        p->drawLine(QLine(QPoint(0,0),QPoint(0,45)));
        p->drawLine(QLine(QPoint(0,0),QPoint(windowWidth,0)));
        p->drawLine(QLine(QPoint(windowWidth,45),QPoint(windowWidth,0)));
        p->end();
        return;
    }
    p->setBrush(QBrush(QColor(255,255,255)));
    p->drawRect(QRect(0,0,width,45));
    p->setPen(QColor(240,240,240));
    p->drawLine(QLine(QPoint(0,45),QPoint(width,45)));
    p->drawLine(QLine(QPoint(0,0),QPoint(0,45)));
    p->drawLine(QLine(QPoint(0,0),QPoint(width,0)));
    p->drawLine(QLine(QPoint(width,45),QPoint(width,0)));
    p->end();
    qDebug()<<"paint"<<qrand()%100;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        m_pressed = true;
        startPos = e->pos();
        if(startPos.y()>45)
            return;
    }
    return QMainWindow::mousePressEvent(e);
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(!m_pressed || startPos.y()>45)
        return;
    int x = this->x()+e->pos().x()-startPos.x();
    int y = this->y()+e->pos().y()-startPos.y();
    this->move(x,y);
}

void MainWindow::on_close_clicked()
{
    qApp->quit();
}

void MainWindow::on_max_clicked()
{
    qDebug()<<windowState();
    if(windowState() & Qt::WindowMaximized || windowState() & Qt::WindowFullScreen)
    {
        this->setWindowState(Qt::WindowNoState);
        ui->max->setIcon(QIcon(":/Max.png"));
        ui->close->move(width-45,0);
        ui->max->move(width-90,0);
        ui->min->move(width-135,0);
        return;
    }
    else if(windowState() == Qt::WindowNoState)
    {
        this->setWindowState(Qt::WindowMaximized);
        ui->max->setIcon(QIcon(":/Normal.png"));
        ui->close->move(windowWidth-45,0);
        ui->max->move(windowWidth-90,0);
        ui->min->move(windowWidth-135,0);
        repaint();
    }
}

void MainWindow::on_min_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}
