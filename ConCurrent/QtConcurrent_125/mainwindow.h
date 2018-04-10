#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_filter_clicked();

private:
    Ui::MainWindow *ui;

    static bool filter(const QString& s);   //声明形式:bool function(const T &t);
};

#endif // MAINWINDOW_H
