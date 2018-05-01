#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myobj.h"
#include <QThread>
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
    void appendText(QString lineTemp);
    void on_pushButton_clicked();
signals:
    void closeMe();
private:
    Ui::MainWindow *ui;
    MyObj* obj;
    QThread *t;
protected:
    void closeEvent(QCloseEvent* e);
};

#endif // MAINWINDOW_H
