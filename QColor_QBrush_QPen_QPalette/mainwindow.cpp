#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(-200,-200,400,400); //场景坐标系,超出view大小加滑条
    scene->setBackgroundBrush(QBrush(QColor(33,40,48)));
    ui->View->setScene(scene);

    rect = scene->addRect(-100,-100,150,150,QPen(Qt::white));
//    改变window背景色和按钮文本颜色
    palette.setColor(QPalette::Window, Qt::lightGray);  //改变控件背景色
    palette.setColor(QPalette::ButtonText, Qt::blue);   //改变控件字体颜色

    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_penBtn_clicked()
{
    // 两种常用的定义QColor方式
    p.setColor(QColor(Qt::yellow));
//    p.setColor(QColor(122,103,238));   //rgb 赋值
    p.setStyle(Qt::DashLine);   // 样式, 类型Qt::PenStyle
    p.setWidthF(3.5);
    rect->setPen(p);


}

void MainWindow::on_brushBtn_clicked()
{
    b.setColor(QColor(122,103,238));
    b.setStyle(Qt::CrossPattern);   // 填充风格, 类型Qt::BrushStyle
    rect->setBrush(b);
}
