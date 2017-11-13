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
    void on_btn_clicked();

private:
    Ui::MainWindow *ui;
    void _QDateTime();
    void _QDate();
    void _QTimeZone();
    void _QTime();
    bool hasFeb29(QDateTime min, QDateTime max);
};

#endif // MAINWINDOW_H
