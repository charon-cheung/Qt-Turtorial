#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QHostAddress>
#include <QHostInfo>
#include <QMainWindow>
#include <QNetworkInterface>
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
};

#endif // MAINWINDOW_H
