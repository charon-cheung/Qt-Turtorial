#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QThread>
#include <QMainWindow>
#include <QDebug>
#include <QSemaphore>

namespace Ui {
class MainWindow;
}


class Thread_1 : public QThread
{
public:             // 不指定作用域则默认为private
    Thread_1();
    ~Thread_1();
public: void stop();
protected:
    void run();
private:
    bool stop_1;
    int num;
};

class Thread_2 : public QThread
{
    Q_OBJECT
public:
    Thread_2();
    ~Thread_2();
signals:
    void MsgSig(int value);
public:
    void stop();
protected:
    void run();
private:
    bool stop_2;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void ShowMsg(int value);
private:
    Ui::MainWindow *ui;
    Thread_1* t1;
    Thread_2* t2;
};

#endif // MAINWINDOW_H
