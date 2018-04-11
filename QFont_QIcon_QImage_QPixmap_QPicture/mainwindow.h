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
    void on_fontPicker_clicked();

    void on_getFont_clicked();

    void on_zoomIn_clicked();

private:
    Ui::MainWindow *ui;
    QFont TextFont;

    QFont getFont();
};

#endif // MAINWINDOW_H
