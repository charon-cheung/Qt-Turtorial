#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"
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
    void on_ReadBtn_clicked();
    void FinishThread();
    void on_pushButton_clicked();
    void ShowMsg(QString text);
private:
    Ui::MainWindow *ui;
    MyThread* thread;
    QFile* file;
};

#endif // MAINWINDOW_H
