#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
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
    QLabel* label;
    QPushButton* btn;

    void EditStatusBar();
    void EditToolBar();
//    QMenu* createPopupMenu();

    void CreateDock();
};

#endif // MAINWINDOW_H
