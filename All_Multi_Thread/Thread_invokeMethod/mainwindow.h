#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "xthread.h"

//#define ABCD

#ifndef ABCD
namespace Ui {
class MainWindow;
}
#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    Q_INVOKABLE void time();
private slots:
    Q_INVOKABLE void ShowTime(QString time);
private:
    Ui::MainWindow *ui;
    XThread* thread;
    void testAAAAAAAA();
};

#endif // MAINWINDOW_H
