#ifndef MYJOB_H
#define MYJOB_H
#include <QDebug>
#include <QThread>
#include <QFuture>
#include <QtConcurrent>

class MyJob : public QObject
{
    Q_OBJECT
public:
    MyJob();
    void start(QString name);
signals:
    void On_Number(QString name, int num);
public slots:
    void stop();
private:
    bool m_stop;
};

#endif // MYJOB_H
