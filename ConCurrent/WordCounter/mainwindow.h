#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QtConcurrent>
#include <QFuture>
#include <QPaintEvent>
#include <QPainter>
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
    void on_pushButton_clicked();

    void on_toolButton_clicked();
    void on_btn_clicked();

    void on_radioButton_clicked();

    void on_min_clicked();

    void on_max_clicked();

    void on_close_clicked();

private:
    QStringList RecursiveFind(QString dirPath,QStringList suffixes);
    unsigned int GetCountBySingleThread(QStringList files);
    unsigned int GetCountByConcurrent(QStringList name);
    static unsigned int mappedFile(const QString& name);
    static void reduced(unsigned int &result, const unsigned int &interm);
private:
    Ui::MainWindow *ui;
    bool m_pressed;
    QPoint startPos;
protected:
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
