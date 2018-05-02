#ifndef TASK_H
#define TASK_H
#include <QRunnable>
#include <QThread>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QWidget>
class Task : public QObject,public QRunnable
{
    Q_OBJECT
public:
    Task(int id,QWidget* w);
    void run() Q_DECL_OVERRIDE;
    ~Task();
signals:
    void toLine(QString line);
private:
    int m_id;
    QWidget* m_w;
};

#endif // TASK_H
