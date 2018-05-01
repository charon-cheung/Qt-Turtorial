#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "myevent.h"

namespace Ui {
class MainWindow;
}
#include <QMouseEvent>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool m_pressed;
    QPoint startPos;
    int width,windowWidth;
protected:
    bool event(QEvent *event);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void customEvent(QEvent *event);

private slots:
    void on_close_clicked();
    void on_max_clicked();
    void on_min_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
