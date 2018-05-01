#ifndef MYOBJ_H
#define MYOBJ_H
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QThread>
#include <QTimer>
class MyObj : public QObject
{
    Q_OBJECT
public:
    MyObj();
    void Stop();
signals:
    void toLine(QString line);
private slots:
    void doWork();
    void testTimer();
private:
    bool m_stop;
    QTimer* timer;
};

#endif // MYOBJ_H
