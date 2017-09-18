#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    EditStatusBar();
    EditToolBar();
    // add context menu, only show in toolbar
    QMenu* popMenu = createPopupMenu();
    popMenu->exec(QCursor::pos());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::EditStatusBar()
{
    // 状态栏添加QLabel和QPushButton,默认是逐个在右侧添加
    ui->statusBar->showMessage("我是状态栏");
    label = new QLabel(this);
    label->setFont(QFont("Inconsolata",12));
    label->setText("QLabel");
    ui->statusBar->addPermanentWidget(label);

    btn = new QPushButton(this);
    btn->setFont(QFont("Inconsolata",12));
    btn->setText("QPushButton");
    ui->statusBar->addPermanentWidget(btn);
    //窗口的控制点
//    ui->statusBar->setSizeGripEnabled(false);
    //    this->statusBar()
}

void MainWindow::EditToolBar()
{
    // 可以在设计模式中创建QAction,然后直接拖到toolBar,但不能拖到menuBar
    QAction* one = new QAction("one");
    QAction* two = new QAction("two");
    QAction* three = new QAction("three");
    ui->mainToolBar->addAction(one);
    ui->mainToolBar->addAction(two);
    ui->mainToolBar->addAction(three);
    //唯一直接改变所添加widget或action间距的方法,也可以用添加布局的方式
    ui->mainToolBar->setStyleSheet("QToolBar{spacing: 10px;} ");
    ui->mainToolBar->setOrientation(Qt::Vertical);
    ui->mainToolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea | Qt::TopToolBarArea);
}

QMenu* MainWindow::createPopupMenu()
{
    //call the overridden method to get the default menu  containing checkable entries
    //for the toolbars and dock widgets present in the main window
    QMenu* menu= QMainWindow::createPopupMenu();
    //you can add QAction to the menu before returning it
    menu->addSeparator();
    menu->addAction(ui->action111);
    menu->addAction(ui->action222);
    menu->addAction(ui->action333);
    return menu;
}

void MainWindow::CreateDock()
{

}
