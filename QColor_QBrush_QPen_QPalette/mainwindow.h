#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_penBtn_clicked();

    void on_brushBtn_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* rect;

    QPen p;    // 需要include<QPen>, 下面三个类不需要
    QBrush b;
    QColor c;
    QPalette palette;
};

#endif // MAINWINDOW_H
