#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static bool filter(const QString& s);
    static void reduced(QStringList& list,const QString& s);
private slots:
    void on_btn_clicked();
    void start()
    {
        qDebug()<<"started !";
    }
    void finish()
    {
        qDebug()<<"finish !";
    }
    void rangeChanged()
    {
        qDebug()<<"range changed !";
    }
    void valueChange()
    {
        qDebug()<<"value change !";
    }
private:
    Ui::MainWindow *ui;
     QFutureWatcher <QStringList> watcher;
};

#endif // MAINWINDOW_H
