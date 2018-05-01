#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "myevent.h"
#include <QResizeEvent>
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
    int W,windowWidth;
    int H,windowHeight;
protected:
    bool event(QEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void customEvent(QEvent *event);
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_close_clicked();
    void on_max_clicked();
    void on_min_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
