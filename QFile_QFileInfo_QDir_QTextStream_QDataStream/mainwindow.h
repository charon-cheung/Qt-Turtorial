#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileInfo>
#include <QDataStream>
#include <QTextStream>
#include <QDir>
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
    void on_open_file_clicked();

    void on_open_dir_clicked();

    void on_entryInfo_clicked();

    void on_rename_clicked();

    void on_readFile_clicked();

private:
    Ui::MainWindow *ui;
    QString filePath,dirPath;
    QFile file;
    QFileInfo fInfo;
    QDir dir;
};

#endif // MAINWINDOW_H
