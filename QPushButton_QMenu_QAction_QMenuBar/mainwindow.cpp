#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu* btnMenu = new QMenu(this);
//    QList<QAction*> actions;
    actions<< ui->act1 << ui->act2 << ui->act3;
    btnMenu->addActions(actions);

    ui->btn->setMenu(btnMenu);
    ui->btn_2->setMenu(btnMenu);
    // 不带箭头的下拉框
    ui->btn_2->setStyleSheet("QPushButton::menu-indicator{image:None;}");
    // 设计模式中的菜单项顺序无法修改,只能在代码里改变
    ui->menuTest->addAction(ui->act1);
    ui->menuTest->insertAction(ui->act1,ui->act2);
    // 右键菜单,不设置policy则无法发出下面的信号
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(RightMouseMenu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RightMouseMenu()
{
    QMenu m;
    m.addActions(actions);
    m.exec(QCursor::pos());
}

