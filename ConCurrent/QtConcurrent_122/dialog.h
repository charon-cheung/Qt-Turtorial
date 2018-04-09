#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "myjob.h"
#include <QFutureWatcher>
using namespace QtConcurrent;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
signals:
    void on_Stop();
private slots:
    void on_start_clicked();

    void on_stop_clicked();
public slots:
    void New_Num(QString name,int num);
    void NotifyFinished();
private:
    Ui::Dialog *ui;
    QFutureWatcher<void> watcher;
    MyJob *m_job;
};

#endif // DIALOG_H
