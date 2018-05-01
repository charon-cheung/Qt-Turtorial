#ifndef XTHREAD_H
#define XTHREAD_H

#include<QThread>
class XThread : public QThread
{
    Q_OBJECT
    Q_PROPERTY(QString time MEMBER m_time NOTIFY currentTime)
public:
    XThread();

protected:
    void run() Q_DECL_OVERRIDE;
signals:
    void currentTime(const QString &time);
private:
    QString m_time;
};

#endif // XTHREAD_H
