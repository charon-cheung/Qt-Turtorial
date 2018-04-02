#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void SetLastBufferNum(QList<int> buffer);
};

class Thread_1 : public QThread
{
public:
    explicit Thread_1();
    ~Thread_1();
protected:
    void run() Q_DECL_OVERRIDE;
};

class Thread_2 : public QThread
{
    Q_OBJECT
public:
    explicit Thread_2();
    ~Thread_2();
protected:
    void run() Q_DECL_OVERRIDE;
signals:
    void SendData(QList<int> buffer);
};
#endif // MAINWINDOW_H
