#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
#include <QPicture>
#include <QDebug>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile(":/Icon/img/cmake.png");
    // different from app icon, which is configured in .pro
    this->setWindowIcon(icon);

//    QPicture records and replays QPainter commands.
    QPicture picture;
    QPainter painter;
    painter.begin(&picture);           // paint in picture
    painter.drawEllipse(10,20, 50,50); // draw an ellipse
    painter.end();                     // painting done
    picture.save("drawing.pic");       // save picture
    ui->picLabel->setPicture(picture);

    // QLabel can't load QImage, only can load a QPixmap converted from QImage
    QImage image(":/Icon/img/ibus.png");

//    use QPixmap to load picture
    QPixmap pix;
    pix.convertFromImage(QImage(":/Icon/img/cloud.png"));
//    pix.load(":/Icon/img/cloud.png");
    qDebug()<< pix.size();
    ui->pixLabel->setPixmap(pix);

    // conversion between QPixmap and QImage
    QPixmap pixmap = QPixmap::fromImage(QImage(":/Icon/img/ibus.png"),Qt::AutoColor);
    ui->imageLabel->setPixmap(pixmap);
    QImage i = pixmap.toImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fontPicker_clicked()
{
    bool ok;    // 不要ok也行
    TextFont = QFontDialog::getFont(&ok, QFont("Inconsolata", 12), 0);
    ui->txtLabel->setFont(TextFont);
}

QFont MainWindow::getFont()
{   emit toStr();
    QFont font;
    font.setPointSizeF(16.5);
    font.setFamily("Inconsolata");
    font.setBold(true);
    font.setItalic(true);   // 斜体
    return font;
}

void MainWindow::on_getFont_clicked()
{
    ui->txtLabel->setFont(getFont());
}

void MainWindow::on_zoomIn_clicked()
{
    QPixmap cloud = ui->pixLabel->pixmap()->scaled(200,200);
    QPixmap ibus = ui->imageLabel->pixmap()->scaled(200,200);
    ui->pixLabel->setPixmap(cloud);
    ui->imageLabel->setPixmap(ibus);
}
