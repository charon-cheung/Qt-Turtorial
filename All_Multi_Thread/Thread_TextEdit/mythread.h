#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QDebug>
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QTextEdit* edit);
    void stop();
    QFile* file;
    bool m_stop;
    QTextEdit* m_edit;
protected:
    void run() Q_DECL_OVERRIDE;
signals:
    void TransferMsg(QString msg);
private:

};

#endif // MYTHREAD_H
